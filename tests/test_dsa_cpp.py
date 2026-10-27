#!/usr/bin/env python3
"""Test existing published DSA examples without changing student source files.
Run from any folder: python tests/test_dsa_cpp.py [repository-path]
Requires Python 3 and g++ on PATH. Builds only into a temporary directory.
"""
from pathlib import Path
import random
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(sys.argv.pop(1)).resolve() if len(sys.argv) > 1 else Path(__file__).resolve().parents[1]
BASE = ROOT / 'C++' / 'C++'


class DsaExamples(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp = tempfile.TemporaryDirectory()
        cls.out = Path(cls.temp.name)
        cls.executables = {}
        for name, file in [('matrix', 'Array/A1.cpp'), ('poly', 'Array/A2.cpp'),
                           ('odd_even', 'Stack/S2.cpp')]:
            cls.executables[name] = cls.compile(BASE / file, name)

    @classmethod
    def tearDownClass(cls):
        cls.temp.cleanup()

    @classmethod
    def compile(cls, source, name):
        exe = cls.out / (name + '.exe')
        subprocess.run(['g++', '-std=c++17', '-Wall', '-Wextra', '-Wpedantic',
                        '-pedantic-errors', str(source), '-o', str(exe)], check=True)
        return exe

    def run_program(self, name, text, expected_code=0):
        run = subprocess.run([str(self.executables[name])], input=text,
                             text=True, capture_output=True, timeout=5)
        self.assertEqual(run.returncode, expected_code, run.stderr)
        return run.stdout

    def harness(self, relative, name, body):
        path = (BASE / relative).as_posix()
        source = self.out / (name + '.cpp')
        source.write_text('#include <cassert>\n#define main example_main\n#include "' + path +
                          '"\n#undef main\nint main() {\n' + body + '\n}\n', encoding='utf-8')
        exe = self.compile(source, name)
        run = subprocess.run([str(exe)], capture_output=True, text=True, timeout=5)
        self.assertEqual(run.returncode, 0, run.stderr)

    def test_matrix_randomized_addition(self):
        rng = random.Random(20261027)
        for _ in range(50):
            rows, cols = rng.randint(1, 6), rng.randint(1, 6)
            a = [rng.randint(-10, 10) for _ in range(rows * cols)]
            b = [rng.randint(-10, 10) for _ in range(rows * cols)]
            text = f'{rows} {cols}\n' + ' '.join(map(str, a + b)) + '\n'
            output = self.run_program('matrix', text)
            actual = output.split('Sparse matrix C (A + B) :')[1].strip().splitlines()[1:]
            expected = [f'{i // cols}\t{i % cols}\t{x + y}'
                        for i, (x, y) in enumerate(zip(a, b)) if x + y != 0]
            self.assertEqual(actual, expected)

    def test_matrix_cancellation(self):
        output = self.run_program('matrix', '1 2\n3 -5\n-3 5\n')
        self.assertEqual(output.split('Sparse matrix C (A + B) :')[1].strip(), 'Row\tCol\tValue')

    def test_matrix_largest_size(self):
        output = self.run_program('matrix', '20 20\n' + ' '.join(['1'] * 800))
        self.assertIn('19\t19\t2', output)

    def test_matrix_overflow_regression(self):
        self.assertIn('4294967294', self.run_program('matrix', '1 1\n2147483647\n2147483647\n'))

    def test_matrix_invalid_inputs(self):
        for text in ['0 1\n', '21 20\n', '-1 1\n', 'x\n', '1 1\nx\n', '1 1\n2\n']:
            with self.subTest(text=text):
                self.run_program('matrix', text, 1)

    def test_polynomial_merge_and_order(self):
        self.harness('Array/A2.cpp', 'poly_merge', '''
    termCount = 0;
    addTerm(initTerm(1, 3)); addTerm(initTerm(5, 2)); addTerm(initTerm(1, 4));
    assert(termCount == 2);
    assert(poly[0].exp == 5 && poly[0].coeff == 2);
    assert(poly[1].exp == 1 && poly[1].coeff == 7);
''')

    def test_polynomial_full_capacity(self):
        self.harness('Array/A2.cpp', 'poly_capacity', '''
    termCount = 0;
    for(int i = 0; i < 100; ++i) addTerm(initTerm(i, 1));
    assert(termCount == 100);
    addTerm(initTerm(100, 99)); assert(termCount == 100);
    addTerm(initTerm(99, 2)); assert(poly[0].coeff == 3);
''')

    def test_polynomial_zero_and_bad_input(self):
        self.assertIn('The polynomial is: 0', self.run_program('poly', '0\n'))
        for text in ['101\n', '-1\n', 'x\n', '1\n2 x\n']:
            with self.subTest(text=text):
                self.run_program('poly', text, 1)

    def test_array_stack_lifo_and_empty(self):
        self.harness('Stack/S1.cpp', 'stack_lifo', '''
    Stack s; assert(s.isEmpty()); assert(s.pop() == -1); assert(s.peek() == -1);
    s.push(10); s.push(-1); s.push(30);
    assert(s.peek() == 30); assert(s.pop() == 30); assert(s.pop() == -1);
    assert(s.pop() == 10); assert(s.isEmpty());
''')

    def test_array_stack_overflow_preserves_contents(self):
        self.harness('Stack/S1.cpp', 'stack_capacity', '''
    Stack s;
    for(int i = 0; i < MAX; ++i) s.push(i);
    assert(s.isFull()); s.push(999); assert(s.peek() == MAX - 1);
    for(int i = MAX - 1; i >= 0; --i) assert(s.pop() == i);
    assert(s.isEmpty());
''')

    def test_stack_odd_even_including_negatives(self):
        output = self.run_program('odd_even', '5\n-3 -2 0 4 7\n')
        self.assertIn('Odd elements: -3 7', output)
        self.assertIn('Even elements: -2 0 4', output)

    def test_stack_invalid_inputs(self):
        for text in ['101\n', '-1\n', 'x\n', '2\n1\n', '1\nx\n']:
            with self.subTest(text=text):
                self.run_program('odd_even', text, 1)

    def test_linked_stack_lifo_reuse_and_scope(self):
        self.harness('Stack/S3.cpp', 'linked_lifo', '''
    for(int round = 0; round < 10; ++round) {
        Stack s; assert(s.isEmpty()); assert(s.pop() == -1);
        for(int i = 0; i < 100; ++i) s.push(i);
        for(int i = 99; i >= 0; --i) assert(s.pop() == i);
        assert(s.isEmpty()); s.push(7); assert(s.peek() == 7);
        // The destructor owns the remaining node. Sanitizers can check its release.
    }
''')


if __name__ == '__main__':
    unittest.main(verbosity=2)
