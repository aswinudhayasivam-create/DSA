# DSA
## Daily uploads

The scheduled GitHub Actions job reads `source/` in this repository, not files
on your laptop. It selects one new content hash per run (C first, then C++),
compiles the selected standalone program, and only publishes it if compilation
succeeds. Compiler warnings appear in the log; compilation is not a full test
of program behavior. A broken first candidate blocks the queue until corrected.

Check the job summary for the queue count and selected program. An empty queue
is a successful no-op, not a new upload. Add genuinely new code to `source/`
and push it before expecting more uploads. Existing duplicates are not repeated.
Concurrent uploader runs are serialized to avoid two runs publishing together.
