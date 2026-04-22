# California Priority Scheduler (`california_prio.c`) — Beginner Explanation

## 1. Title
Non-Preemptive Priority CPU Scheduling in C (Fixed Process Set, Deterministic Tie-Break)

## 2. Quick Diagnostic Read
You are ready for this guide if you can read C arrays, `struct`s, and `for`/`while` loops.

High-value concepts in this file:
- How non-preemptive priority scheduling is represented in code.
- Why waiting time, response time, and turnaround time can be computed in simple passes.
- How stable tie-breaking is implemented for equal priorities.

## 3. One-Sentence Objective
Understand how this single C program sorts processes by priority, computes scheduling metrics, and prints the execution order and summary table.

## 4. Why This File Matters
This file is a complete, minimal implementation of non-preemptive priority scheduling logic. It is small enough to study end-to-end but still includes core scheduling metrics (`WT`, `RT`, `TAT`) and deterministic ordering rules. If you understand this file, you can extend it toward arrival times, preemption, or dynamic input.

## 5. Plan A / Plan B
Plan A (Code-first, 30-45 min):
- Read sections 9 and 10 while keeping the source open.
- Manually compute metrics for the given 4 processes.
- Compare with section 12 execution trace.

Plan B (Concept-first, 20-35 min):
- Read sections 6, 11, and 15 first (mental model + contracts).
- Then read section 10 to map each concept to code lines.

## 6. System View / Mental Model
```text
Input process array (pid, bt, prio)
        |
        v
sort_by_priority()
  - higher prio first
  - tie: lower pid first
        |
        v
compute_waiting_times()
  WT[i] = sum(BT of all earlier scheduled processes)
        |
        +--> compute_response_times()
        |      RT[i] = WT[i]   (non-preemptive, all arrival at t=0)
        |
        +--> compute_turnaround_times()
               TAT[i] = WT[i] + BT[i]
        |
        v
compute_averages()
        |
        v
print_execution_order() + print_table()
```

## 7. What This File Is and Where It Fits
- File type: C source file.
- Role: standalone demonstration program for non-preemptive priority scheduling.
- Immediate consumers: none inside repo were required for understanding this target (standalone `main`).
- Dependencies: C standard I/O via `#include <stdio.h>`.

## 8. Just-Enough Primer
- `typedef struct { ... } Process;` defines a record type for each process.
- `static` on helper functions limits linkage to this translation unit (file-local helpers).
- Arrays are fixed-size using `#define N 4` and stack allocation (`Process processes[N]`).
- Pointers in `compute_averages(..., double *avg_wt, ...)` are used to return multiple outputs.

## 9. Whole-File Outline Mapped to Code Regions
- Lines 1-4: File header comment + include + process count constant.
- Lines 6-10: `Process` struct (`pid`, `bt`, `prio`).
- Lines 12-26: `sort_by_priority` (insertion sort with tie-break rule).
- Lines 28-34: `compute_waiting_times`.
- Lines 36-41: `compute_response_times`.
- Lines 43-48: `compute_turnaround_times`.
- Lines 50-66: `compute_averages`.
- Lines 68-78: `print_execution_order`.
- Lines 80-93: `print_table`.
- Lines 95-119: `main` (data setup, call sequence, output).

## 10. Walkthrough by Section
### Header, include, constant (lines 1-4)
- What it does: Declares this as non-preemptive priority scheduling and sets fixed process count `N=4`.
- Why it exists: Keeps example deterministic and compact.
- Side effects/contracts: All arrays in `main` depend on `N`; changing `N` requires matching initializer size.

### `Process` struct (lines 6-10)
- What it does: Stores process ID, burst time (`bt`), and priority (`prio`).
- Data in/out: Input is literal initialization in `main`; fields are read by metric functions.
- Invariant: `bt` should be non-negative for meaningful scheduling metrics (not validated in code).

### `sort_by_priority` (lines 12-26)
- What it does: Reorders `processes[]` in descending priority; if priorities tie, lower `pid` comes first.
- How it works: Insertion sort shifts earlier elements right while comparison condition is true.
- Key condition (lines 18-20): shift when earlier process has lower priority or same priority with larger pid.
- Side effects: Mutates `processes[]` in place.
- Dangerous change point: Reversing comparison direction silently changes scheduler policy.

### `compute_waiting_times` (lines 28-34)
- What it does: Sets `wt[0]=0`, then cumulative sum of previous burst times.
- How it works: `wt[i] = wt[i-1] + processes[i-1].bt`.
- Contract: Assumes sorted order already represents execution order.
- Break risk: Calling this before sorting yields wrong schedule metrics for priority policy.

### `compute_response_times` (lines 36-41)
- What it does: Copies waiting times into response times.
- Why this is valid: In this model, each process starts once and runs to completion (non-preemptive, no arrival-time offsets).
- Side effects: Writes `rt[]` only.

### `compute_turnaround_times` (lines 43-48)
- What it does: Computes `tat[i] = wt[i] + bt[i]`.
- Data flow: Reads sorted `processes[]` and `wt[]`, writes `tat[]`.
- Contract: Requires `wt[]` already computed.

### `compute_averages` (lines 50-66)
- What it does: Sums each metric array and divides by `n` to compute averages.
- How it works: Integer totals, then cast to double at division (line 63 onward).
- Side effects: Writes via output pointers (`avg_wt`, `avg_rt`, `avg_tat`).
- Break risk: `n` must be > 0 to avoid division by zero (guaranteed here by `N=4`).

### `print_execution_order` (lines 68-78)
- What it does: Prints process IDs in scheduled order (e.g., `P3, P1, ...`).
- Why it exists: Makes order explicit before metrics table.

### `print_table` (lines 80-93)
- What it does: Prints per-process metrics and average metrics.
- Data flow: Consumes final arrays and averages; no mutation.
- Note: Formatting alignment is manual via width specifiers in `printf`.

### `main` (lines 95-119)
- What it does: Initializes sample data, runs pipeline, prints results, returns success.
- Concrete setup (lines 96-101):
  - P1: BT=10 PRIO=3
  - P2: BT=6 PRIO=1
  - P3: BT=4 PRIO=4
  - P4: BT=8 PRIO=2
- Call order is the core contract:
  1. sort
  2. waiting
  3. response
  4. turnaround
  5. averages
  6. print

## 11. Data Flow / Control Flow / Dependency Map
Control flow is strictly linear from `main`:
- `processes` is first mutated by sorting.
- Derived arrays (`wt`, `rt`, `tat`) are filled in dependency order.
- Averages depend on all three arrays.
- Output functions are last and read-only.

Dependencies:
- External: `stdio.h` only.
- Internal function dependencies:
  - `compute_waiting_times` depends on sorted `processes`.
  - `compute_response_times` depends on `wt`.
  - `compute_turnaround_times` depends on `processes` and `wt`.
  - `compute_averages` depends on all metric arrays.

## 12. Minimal Usage Example or Execution Trace
Hypothetical manual trace using the hardcoded input (this matches the actual code path):

1. Sort by priority descending:
- Order becomes: P3(prio4), P1(prio3), P4(prio2), P2(prio1)

2. Waiting times:
- WT(P3)=0
- WT(P1)=0+4=4
- WT(P4)=4+10=14
- WT(P2)=14+8=22

3. Response times (copy WT):
- RT = [0, 4, 14, 22]

4. Turnaround times:
- TAT(P3)=0+4=4
- TAT(P1)=4+10=14
- TAT(P4)=14+8=22
- TAT(P2)=22+6=28

5. Averages:
- Avg WT = (0+4+14+22)/4 = 10.00
- Avg RT = 10.00
- Avg TAT = (4+14+22+28)/4 = 17.00

## 13. Common Pitfalls / Misconceptions
- Assuming higher numeric priority means lower urgency. In this file, higher number means higher priority (line 1).
- Forgetting that response time equals waiting time only under this simplified non-preemptive model.
- Changing sort logic without updating comments/tests causes policy mismatch.
- Believing this handles arrival times; it does not.

## 14. Safe-Change Guide
Low-risk changes:
- Change sample process data in `main` and recalculate expected outputs.
- Improve output formatting in `print_table`.
- Increase `N` and add matching initializers.

Higher-risk changes:
- Sort comparison logic (lines 18-20): affects entire scheduling policy.
- Metric formulas: small changes can invalidate all reported values.
- Introducing arrival times without redesigning `compute_waiting_times` and `compute_response_times`.

## 15. Invariants / Contracts / Side Effects
Observed invariants/contracts:
- Scheduler order is exactly the sorted `processes[]` order.
- `wt[0]` is always `0` (line 30).
- `rt[i] == wt[i]` for all `i` (lines 36-40).
- `tat[i] == wt[i] + bt[i]` (line 46).
- `n > 0` is required for average division.

Side effects:
- In-place mutation of `processes[]` in `sort_by_priority`.
- Console output in `print_execution_order` and `print_table`.

Inference (explicit):
- This appears to be an instructional/demo program rather than production scheduler integration, based on fixed-size hardcoded input and single-file design.

## 16. Self-Check or Practice Drill
Exercise (20-40 min):
- Add a fifth process `P5` with `BT=5`, `PRIO=3`.
- Predict execution order using tie-break rule (`pid` ascending when priorities tie).
- Manually compute WT/RT/TAT and averages.
- Run and compare with program output.

Self-check rubric:
- You correctly place `P1` before `P5` (same priority, lower pid wins).
- Your WT sequence is cumulative and non-decreasing.
- Your RT equals WT at every index.
- Your TAT equals WT+BT at every index.

## 17. Artifact Map
Target file read:
- `cmsc-125-cpu-scheduling/california_prio.c` (full source of truth for all behavior claims).

Supporting files read:
- `agent/action/explain.task` (execution contract).
- `agent/reference/sample-study-guide-docs.md` (output style baseline).
- `agent/rules/system-prompt.md` (teaching/behavior alignment).
- `agent/rules/PROFILE.md` (learner calibration context).

No additional code/context files were required for truthful explanation of this standalone file.

## 18. Copy-Paste Prompt Examples
```text
explain.task cmsc-125-cpu-scheduling/california_prio.c
explain.task cmsc-125-cpu-scheduling/california_prio.c "sort_by_priority"
explain.task cmsc-125-cpu-scheduling
```

## 19. 24-72 Hour Next Steps
1. Add arrival-time support and update waiting-time logic.
2. Implement a preemptive priority variant and compare metrics.
3. Write unit tests for tie-breaking and formula correctness.
4. Add input validation (non-negative burst times, positive process count).