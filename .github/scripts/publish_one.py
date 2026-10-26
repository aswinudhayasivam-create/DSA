#!/usr/bin/env python3
"""Publish one new, compilable C/C++ program. No external Python packages."""
import hashlib
import os
from pathlib import Path
import shutil
import subprocess
import tempfile


def digest(path):
    return hashlib.sha256(path.read_bytes()).digest()


def summary(text):
    print(text)
    if os.environ.get('GITHUB_STEP_SUMMARY'):
        with open(os.environ['GITHUB_STEP_SUMMARY'], 'a', encoding='utf-8') as out:
            out.write(text + '\n')


def main():
    root = Path(__file__).resolve().parents[2]
    source = root / 'source'
    if not source.is_dir():
        raise SystemExit('Missing source/ directory. No files published.')
    published = {digest(p) for folder in ['C', 'C++']
                 for p in (root / folder).rglob('*') if p.is_file()}
    candidates = []
    seen = set(published)
    for p in sorted(source.rglob('*'), key=lambda p: (p.suffix.lower() != '.c', p.as_posix())):
        if not p.is_file() or p.suffix.lower() not in {'.c', '.cpp', '.cc', '.cxx'}:
            continue
        content_hash = digest(p)
        if content_hash in seen:
            continue
        seen.add(content_hash)
        candidates.append(p)
    summary(f'## DSA daily upload\nNew unique programs in queue: {len(candidates)}')
    if not candidates:
        summary('Queue empty: all source programs are already published or duplicates. '
                'Add new code to source/ to resume uploads. Nothing was committed.')
        return
    selected = candidates[0]
    language = 'C' if selected.suffix.lower() == '.c' else 'C++'
    relative = selected.relative_to(source)
    summary(f'Selected {language} program: `{relative.as_posix()}`')
    compiler, standard = ('gcc', 'c11') if language == 'C' else ('g++', 'c++17')
    with tempfile.TemporaryDirectory() as out:
        result = subprocess.run([compiler, f'-std={standard}', '-Wall', '-Wextra',
                                 str(selected), '-o', str(Path(out) / 'program')],
                                capture_output=True, text=True, timeout=60)
    if result.stdout:
        print(result.stdout)
    if result.stderr:
        print(result.stderr)
    if result.returncode:
        summary('Compilation failed. No file copied or committed. Fix the selected source '
                'program before retrying; see compiler diagnostics in the job log.')
        raise SystemExit(1)
    destination = root / language / relative
    destination.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(selected, destination)
    subprocess.run(['git', 'config', 'user.name', 'Aswin Udhaya'], cwd=root, check=True)
    subprocess.run(['git', 'config', 'user.email',
                    '243352642+aswinudhayasivam-create@users.noreply.github.com'], cwd=root, check=True)
    subprocess.run(['git', 'add', '--', str(destination.relative_to(root))], cwd=root, check=True)
    subprocess.run(['git', 'commit', '-m', f'Add {language} solution: {selected.name}'], cwd=root, check=True)
    subprocess.run(['git', 'push'], cwd=root, check=True)
    summary(f'Published exactly one compile-checked program: `{destination.relative_to(root).as_posix()}`. '
            'Compilation is not a full correctness test.')


if __name__ == '__main__':
    main()
