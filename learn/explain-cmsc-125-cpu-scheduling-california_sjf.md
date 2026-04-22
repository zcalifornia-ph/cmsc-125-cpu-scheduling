# Explain Guide: `cmsc-125-cpu-scheduling/california_sjf.c`

## 1. Title
Non-Preemptive SJF Scheduler Walkthrough (`california_sjf.c`)

## 2. Quick Diagnostic Read
Prerequisites: basic C syntax (`struct`, arrays, loops, functions) and core CPU scheduling metrics (`WT`, `RT`, `TAT`).

High-value part of this file: it cleanly separates SJF into steps (sort -> compute metrics -> print), so you can see exactly how each metric is derived.

## 3. One-Sentence Objective
Understand how this file computes non-preemptive Shortest Job First ordering and derives waiting, response, and turnaround times for a fixed process dataset.

## 4. Why This File Matters
This file is a compact, reference implementation of one scheduling policy. It is useful as a correctness baseline for comparing other algorithms (for example FCFS or priority scheduling) because all computations are explicit and deterministic.

## 5. Plan A / Plan B
Plan A (code-first, 25-35 min): read `main`, then each helper in call order.

Plan B (concept-first, 25-35 min): manually compute SJF order and metrics on paper, then verify each computation function.

## 6. System View / Mental Model
```text
Input dataset (pid, bt)
  -> sort_by_burst_time (ascending bt, tie: smaller pid)
  -> compute_waiting_times (prefix sum of previous bt)
  -> compute_response_times (rt = wt in non-preemptive SJF)
  -> compute_turnaround_times (tat = wt + bt)
  -> compute_averages
  -> print_table
```

## 7. What This File Is and Where It Fits
- File type: C source file.
- Role: standalone scheduler demo/program.
- Direct dependency: standard I/O (`stdio.h`).
- Consumers: end user running the binary and reading the printed schedule table.

Inference: this file is part of a multi-algorithm CPU scheduling set because of its specific filename (`california_sjf.c`).

## 8. Just-Enough Primer
- `typedef struct { ... } Process;` defines a record for each process.
- `static` functions are translation-unit local (private to this `.c` file).
- Arrays are passed to functions as pointers; modifications affect original data.

## 9. Whole-File Outline Mapped to Code Regions
- Lines 1-5: header comments and include.
- Lines 7-15: constants and `Process` struct.
- Lines 17-32: `sort_by_burst_time` (insertion sort by burst time, tie-break by PID).
- Lines 34-41: `compute_waiting_times`.
- Lines 43-48: `compute_response_times`.
- Lines 50-55: `compute_turnaround_times`.
- Lines 57-73: `compute_averages`.
- Lines 75-101: `print_table`.
- Lines 103-123: `main` dataset initialization and pipeline execution.

## 10. Walkthrough by Section
### Header, constants, and model (lines 1-15)
The file declares non-preemptive SJF intent and defines `PROCESS_COUNT` as `5`. `Process` stores `pid`, `bt`, `wt`, `rt`, `tat`. This model keeps all computed metrics attached to each process row.

### Sorting stage (lines 17-32)
`sort_by_burst_time` uses insertion sort. Primary key is `bt` ascending; secondary key is `pid` ascending (implemented by shifting when `processes[j].pid > key.pid` under equal burst). This makes tie handling deterministic.

### Waiting time stage (lines 34-41)
`processes[0].wt = 0` for the first scheduled process. Every next waiting time is cumulative prior work: `wt[i] = wt[i-1] + bt[i-1]`. This is a prefix-sum pattern.

### Response time stage (lines 43-48)
`rt[i] = wt[i]`. For non-preemptive scheduling, response time equals waiting time because each process starts once and is never interrupted.

### Turnaround stage (lines 50-55)
`tat[i] = wt[i] + bt[i]`, representing total time from arrival (implicitly 0 for all in this simplified model) to completion.

### Aggregation stage (lines 57-73)
Sums all `wt`, `rt`, `tat` into integer totals, then divides by `count` into `double` averages. Type cast `(double)` prevents integer-division truncation.

### Output stage (lines 75-101)
Prints execution order (`P<id>` sequence), then a metrics table, then averages. This makes intermediate correctness easy to inspect.

### Orchestration in `main` (lines 103-123)
Defines fixed dataset:
- P1=8, P2=4, P3=9, P4=5, P5=2 (burst times)

Then runs helpers in logical order and prints results.

## 11. Data Flow / Control Flow / Dependency Map
Control flow is strictly linear: `main` calls six helper functions in sequence; no branches in orchestration.

Data flow:
- `processes[]` is mutated in-place by sort and metric-computation functions.
- `avg_wt`, `avg_rt`, `avg_tat` are output via pointers in `compute_averages`.
- `print_table` consumes finalized array + averages.

Dependency map:
- Internal: every metric function depends on prior sorting for correct schedule order.
- External: only `stdio.h`.

## 12. Minimal Usage Example or Execution Trace
Hypothetical execution trace using current dataset:
- Sorted order by burst: `P5(2), P2(4), P4(5), P1(8), P3(9)`
- WT: `0, 2, 6, 11, 19`
- RT: `0, 2, 6, 11, 19`
- TAT: `2, 6, 11, 19, 28`
- Averages: `WT=7.60`, `RT=7.60`, `TAT=13.20`

## 13. Common Pitfalls / Misconceptions
- Assuming it handles arrival times: it does not; all arrivals are implicitly treated as ready at start.
- Assuming preemption exists: it does not; this is non-preemptive only.
- Forgetting tie-break rules: equal burst times are ordered by smaller PID.

## 14. Safe-Change Guide
Safer edits:
- Change the initial dataset values in `main`.
- Change print formatting in `print_table`.

Risky edits:
- Modifying sort comparison logic (can silently change fairness/determinism).
- Reordering pipeline calls in `main` (can produce invalid metrics).
- Changing metric formulas without updating all dependent assumptions.

## 15. Invariants / Contracts / Side Effects
- Invariant: after sorting, `processes` is nondecreasing by `bt`, then by `pid` for ties.
- Invariant: `wt[0] == 0`; for `i>0`, `wt[i] == wt[i-1] + bt[i-1]`.
- Contract: `count > 0` is required (code assumes `processes[0]` exists).
- Side effect: helper functions mutate `processes[]` in place.

## 16. Self-Check or Practice Drill
Exercise (20-30 min): add a new process with `pid=6, bt=5` and predict full table before running.

Self-check rubric:
- You correctly place `P6` among equal burst-time processes using PID tie-break.
- Your WT/RT/TAT values match program output.
- You can explain why `RT == WT` still holds.

## 17. Artifact Map
Files read for this explanation:
- `cmsc-125-cpu-scheduling/california_sjf.c` (target source file).
- `agent/action/explain.task` (task contract and required section structure).
- `agent/reference/sample-study-guide-docs.md` (style/template baseline).
- `agent/rules/system-prompt.md` (teaching/operating behavior constraints).
- `agent/rules/PROFILE.md` (local learner-context calibration).

Note: the source comment references `ai-dlc-docs/design-artifacts/shared-dataset-spec.md`, but that path was not found in this repository snapshot.

## 18. Copy-Paste Prompt Examples
```text
explain.task cmsc-125-cpu-scheduling/california_sjf.c
explain.task cmsc-125-cpu-scheduling/california_sjf.c "sort_by_burst_time"
explain.task cmsc-125-cpu-scheduling
```

## 19. 24-72 Hour Next Steps
1. Implement FCFS in a sibling file with the same output schema.
2. Add arrival-time-aware non-preemptive SJF and compare metric changes.
3. Build one shared validator script to diff expected vs. computed WT/RT/TAT for multiple datasets.