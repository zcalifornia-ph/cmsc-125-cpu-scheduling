# Explain Guide: `cmsc-125-cpu-scheduling/california_rr.c`

## 1) Title
Round Robin Scheduling Walkthrough (`california_rr.c`)

## 2) Quick Diagnostic Read
Prerequisites:
- Basic C syntax: arrays, loops, function calls, pointers.
- CPU scheduling terms: burst time (BT), waiting time (WT), response time (RT), turnaround time (TAT).

High-value ideas in this file:
- How a Round Robin loop is simulated without threads.
- How first dispatch time is captured and reused for response time.
- How derived metrics (WT/RT/TAT averages) are computed from one simulation pass.

## 3) One-Sentence Objective
After reading this guide, you should be able to trace exactly how this C file simulates Round Robin (quantum = 3) and computes per-process and average scheduling metrics.

## 4) Why This File Matters
This file is a compact, end-to-end scheduler simulation: inputs are fixed burst times, core logic computes process timing metrics, and output is a formatted table plus averages. It is useful as a reference implementation for CPU scheduling labs because all key metrics are visible and computed in one place.

## 5) Plan A / Plan B
Plan A (code-first, ~35 min):
- Read the whole-file outline.
- Trace `compute_waiting_times` line by line.
- Verify printed metrics using the execution trace.

Plan B (concept-first, ~25 min):
- Read the mental model and data flow first.
- Learn each metric formula (WT, RT, TAT).
- Return to code and map each formula to the exact lines.

## 6) System View / Mental Model
```text
Fixed dataset (PID + BT)
   -> Round Robin simulation (remaining time, clock t, completion tracking)
      -> First dispatch times captured
      -> Waiting times computed on completion
   -> Response time derivation (RT = first dispatch)
   -> Turnaround derivation (TAT = WT + BT)
   -> Averages over PROCESS_COUNT
   -> Console table + average summary
```

Mental model: this program is a deterministic "time-accounting machine." It advances a virtual clock `t`, updates each process's remaining burst, and records metrics when milestones happen (first run, completion).

## 7) What This File Is and Where It Fits
- File type: C source file.
- Role: standalone educational simulation of Round Robin scheduling.
- Consumers: human reader/runner; no module imports from project code.
- Dependencies: only C standard I/O (`stdio.h`).

## 8) Just-Enough Primer
- `#define PROCESS_COUNT 5` and `#define QUANTUM 3` create compile-time constants.
- Arrays like `int bt[]` are passed to functions by pointer.
- Output parameters (e.g., `double *avg_wt`) are written through pointers (`*avg_wt = ...`).
- The scheduler uses a `while` loop for global completion and a nested `for` loop for one RR cycle.

## 9) Whole-File Outline Mapped to Code Regions
- Lines 1-5: header include and constants.
- Lines 7-11: function declarations.
- Lines 13-51: `compute_waiting_times` (core Round Robin simulation).
- Lines 53-57: `compute_response_times`.
- Lines 59-63: `compute_turnaround_times`.
- Lines 65-79: `compute_averages`.
- Lines 81-88: `print_table`.
- Lines 90-109: `main` (dataset setup, function orchestration, final output).

## 10) Walkthrough by Section
### A) Setup and Declarations (lines 1-11)
The file defines two hard constraints: `PROCESS_COUNT = 5` and `QUANTUM = 3`. Function declarations provide clear separation between simulation, metric derivation, aggregation, and display.

If changed carelessly:
- Mismatched array sizes against `PROCESS_COUNT` can corrupt results.

### B) Core Scheduler: `compute_waiting_times` (lines 13-51)
What it does:
- Simulates Round Robin execution using:
  - `remaining[]`: unfinished burst per process.
  - `first_dispatch[]`: first time each process gets CPU.
  - `t`: virtual time.
  - `completed`: finished process count.

How it works:
- Initialization loop copies `bt` into `remaining`, sets first dispatch to `-1`, zeroes outputs.
- Outer `while (completed < PROCESS_COUNT)` keeps cycling until all finish.
- Inner `for` scans processes in fixed order each cycle.
- Skip finished process (`remaining[i] <= 0`).
- On first visit, save `first_dispatch[i] = t`.
- If `remaining[i] > QUANTUM`, run exactly one quantum.
- Else run remaining burst, mark completion, compute `wt[i] = t - bt[i]`.

Why waiting time formula is valid:
- Completion time is the current `t` after last CPU slice.
- `WT = completion_time - burst_time` in this no-arrival-time scenario.

Side effects:
- Mutates `wt`, `rt`, and `tat` arrays.
- Calls downstream metric functions after the simulation.

Risk if modified badly:
- If `completed++` or `remaining[i] = 0` logic is broken, loop can become infinite.

### C) Response Time Derivation (lines 53-57)
`RT` is copied from `first_dispatch[]`. Because all processes are assumed to arrive at time 0, response time equals first dispatch timestamp.

Risk:
- This direct copy becomes incorrect if non-zero arrival times are introduced without redesign.

### D) Turnaround Time Derivation (lines 59-63)
Computes `tat[i] = wt[i] + bt[i]` for each process.

Invariant:
- For every process, `TAT` must equal total time in system (waiting + running).

### E) Average Computation (lines 65-79)
Sums each metric and divides by `PROCESS_COUNT` using `double` casts for fractional precision.

Risk:
- Integer division bugs appear if cast is removed.

### F) Output Table (lines 81-88)
Prints a hardcoded execution order string and then a fixed-width row per process.

Important note:
- The execution order string is not computed dynamically; it is manually encoded for this dataset.

### G) Main Orchestration (lines 90-109)
Defines the dataset:
- `pid = {1,2,3,4,5}`
- `bt = {8,4,9,5,2}`

Then runs pipeline:
1. Simulation + per-process metrics.
2. Average computation.
3. Table and average prints.

## 11) Data Flow / Control Flow / Dependency Map
Data flow:
- Input: `bt[]` from `main`.
- `compute_waiting_times` produces `wt[]`, then calls derivations for `rt[]` and `tat[]`.
- `compute_averages` consumes `wt/rt/tat` and writes `avg_*`.
- `print_table` consumes final arrays and prints.

Control flow:
`main -> compute_waiting_times -> compute_response_times + compute_turnaround_times -> compute_averages -> print_table -> printf averages`

Dependency map:
- Internal dependency: `compute_waiting_times` depends on helper functions for RT/TAT post-processing.
- External dependency: only `<stdio.h>`.

## 12) Minimal Usage Example or Execution Trace
Hypothetical static trace using this file's fixed input (`BT = [8,4,9,5,2]`):
- CPU slices in order: `P1 P2 P3 P4 P5 P1 P2 P3 P4 P1 P3`
- Final metrics:
  - `WT = [17,14,19,18,12]`
  - `RT = [0,3,6,9,12]`
  - `TAT = [25,18,28,23,14]`
- Averages:
  - `Average WT = 16.00`
  - `Average RT = 6.00`
  - `Average TAT = 21.60`

## 13) Common Pitfalls / Misconceptions
- Thinking `print_table` computes execution order: it does not; it prints a hardcoded string.
- Assuming this handles arrival times: it assumes all arrivals at time 0.
- Forgetting that RR fairness here depends on fixed process order in the inner loop.
- Confusing response time and waiting time: they are equal only in special cases, not generally.

## 14) Safe-Change Guide
Safer edits:
- Change `QUANTUM` and rerun/retrace metrics.
- Swap burst-time dataset in `main`.
- Improve output formatting.

Dangerous edits:
- Touching `while (completed < PROCESS_COUNT)` / completion logic.
- Removing `first_dispatch` initialization to `-1`.
- Changing `WT` formula without adjusting model assumptions.

## 15) Invariants / Contracts / Side Effects
Observed invariants:
- `remaining[i]` never increases.
- `completed` increases exactly when a process transitions to done.
- `tat[i] == wt[i] + bt[i]` for all i.
- `rt[i]` is set exactly once via `first_dispatch` value.

Contracts:
- All metric arrays are expected to have length `PROCESS_COUNT`.
- `bt[i]` should be non-negative (inference from scheduling semantics; not validated in code).

Side effects:
- Console output in `print_table` and `main`.
- Mutating arrays passed by pointer/reference semantics.

## 16) Self-Check or Practice Drill
Exercise (20-40 min):
- Change `QUANTUM` from `3` to `2`.
- Keep the same `bt[]`.
- Recompute execution order and WT/RT/TAT manually, then verify by running program output.

Self-check rubric:
- Correct if your manual `WT`, `RT`, and `TAT` match program output for all 5 processes.
- Strong understanding if you can explain at which exact timestamp each process first runs and finishes.

## 17) Artifact Map
Files read for this explanation:
- `cmsc-125-cpu-scheduling/california_rr.c` (target source of truth).
- `agent/action/explain.task` (required task contract for section/content/verification requirements).
- `agent/reference/sample-study-guide-docs.md` (required style/template baseline).

No additional supporting code files were required because this file is standalone and imports only `<stdio.h>`.

## 18) Copy-Paste Prompt Examples
```text
explain.task cmsc-125-cpu-scheduling/california_rr.c
explain.task cmsc-125-cpu-scheduling/california_rr.c "compute_waiting_times"
explain.task cmsc-125-cpu-scheduling
```

## 19) 24-72 Hour Next Steps
1. Add arrival-time support (e.g., `at[]`) and update RT/WT formulas accordingly.
2. Replace hardcoded execution-order print with dynamic Gantt-style capture during simulation.
3. Add guard checks for invalid burst times and test edge cases (`bt=0`, very large `bt`, `QUANTUM=1`).

---
Verification notes:
- All function names, constants, and formulas above are verified against `california_rr.c`.
- Inference is explicitly labeled where assumptions go beyond explicit code (e.g., non-negative burst expectation).
