# C++ DSA exercise guide

This guide covers the existing published examples. It adds no artificial copies
or cosmetic variants. Compile exercises separately because each has its own
`main()`.

## Find an example

| Published file | What it demonstrates | Time | Extra storage |
| --- | --- | --- | --- |
| `C++/C++/Array/A1.cpp` | Convert dense matrices to sorted triplets, then add them | Conversion: O(rows * cols). Addition: O(nonzeroA + nonzeroB) | Fixed buffers for up to 400 entries per matrix |
| `C++/C++/Array/A2.cpp` | Insert polynomial terms in descending exponent order, combining equal exponents | One insertion: O(t), full construction: O(n squared) worst case | Fixed buffer for 100 terms |
| `C++/C++/Stack/S1.cpp` | Fixed-array stack with push, pop and peek | Push/pop/peek: O(1); display: O(n) | Fixed buffer for 100 integers |
| `C++/C++/Stack/S2.cpp` | Array stack with odd/even traversal | Push/pop: O(1); each traversal: O(n) | Fixed buffer for 100 integers |
| `C++/C++/Stack/S3.cpp` | Linked stack that owns and frees its nodes | Push/pop/peek: O(1); display/destruction: O(n) | O(n) nodes |

`t` is the number of distinct stored polynomial terms; `n` is the number of
input terms or stack elements as applicable. These describe the algorithms,
not a measured runtime. The current arrays impose fixed upper limits.

## Matrix addition: A1

Both matrices use the same dimensions. Enter rows and columns (each 1..20),
then all elements of A in row order, then B. Triplets use zero-based row/column
numbers. Zero entries are omitted. Matching coordinates are added; a result
that cancels to zero is omitted.

Example input:

```text
2 2
1 0
0 2
-1 3
0 4
```

The result triplets are `(0, 1, 3)` and `(1, 1, 6)`.
The merge works because `toSparse` produces entries sorted by row, then column.
Two dense 20x20 matrices need at most 400 result positions, not 800, because
coordinates are drawn from the same 20x20 grid.

## Polynomial insertion: A2

Input pairs are **exponent, coefficient**, not coefficient first. At most 100
input terms are accepted. Equal exponents accumulate into a single entry;
shifting maintains descending exponent order.

Example: `(1, 3), (5, 2), (1, 4)` becomes `2x^5 + 7x^1`.
The current display is a raw learning representation: zero coefficients may
remain, and negative coefficients can appear after `+`. This guide does not
claim pretty mathematical formatting or change that behavior.

## Stack boundaries

S1 uses `top` as the next free slot: empty is 0 and full is 100. Elements occupy
`arr[0]` through `arr[top - 1]`. Push into a full stack leaves existing data
unchanged. Pop/peek on an empty stack print a message and return `-1`.

The `-1` sentinel is ambiguous when `-1` is a valid stored value. Check
`isEmpty()` before interpreting a result in code that needs to distinguish
failure from stored data. No API rewrite is included in this proposal.

S2's odd check uses `% 2 != 0`, so negative odd integers are included correctly.
S3 deletes popped nodes and frees any remaining nodes in its destructor.
Copying S3 is disabled because two stacks must not own the same nodes.

## Run reproducible tests on Windows

Install Python 3 and a C++17-capable g++ compiler, then open PowerShell in your
DSA clone. This proposal adds `tests/test_dsa_cpp.py` and this guide only.

```powershell
python tests/test_dsa_cpp.py
```

Or point the test script at a clone without copying it into that clone:

```powershell
python '<extracted proposal>\tests\test_dsa_cpp.py' '<your DSA clone>'
```

The script builds temporary executables and deletes them afterward. It does
not edit student source, change Git history, commit, push or enable uploads.
It uses the existing C++ class/function code through small temporary test
harnesses, rather than duplicating the implementation under test.

Coverage includes 50 deterministic randomized matrix comparisons, maximum
matrix size, cancellation, integer overflow regression, invalid/short input,
polynomial ordering/merging/capacity, stack LIFO, overflow, underflow, negative
parity and linked-stack reuse. A fixed random seed makes failures reproducible.

## Review limits

The proposal passed 13 unittest methods against DSA main commit
`4b60d1b3ea7f20f0dacea8853fec8e2aaf74c54d` using Linux/GCC C++17. One method
runs 50 randomized cases; other methods contain multiple boundary checks.
These are not 13 total input cases. Windows execution has not been verified.

`A3.cpp` is unfinished and excluded pending the original question/code.
Historical C examples, every possible input and allocation-failure paths are
not covered. Passing tests do not prove all repository programs correct.

The DSA daily uploader remains paused. The tests are an optional local suite;
this proposal does not alter a workflow or start any scheduled work.
