# Version 1.0.3 Documentation

## Title

Round Robin responsibility-separation refactor: simulation is now isolated from metric post-processing.

## Quick Diagnostic Read

Version `1.0.3` refines the Round Robin implementation structure in `california_rr.c` without changing algorithm results.

What changed:

- renamed `compute_waiting_times(...)` to `simulate_rr(...)`,
- removed embedded post-processing calls from the simulator,
- made `main()` call helper stages explicitly in sequence:
  - `simulate_rr(...)`
  - `compute_response_times(...)`
  - `compute_turnaround_times(...)`
  - `compute_averages(...)`

What stayed the same:

- dataset, quantum, and computed output values for WT/RT/TAT,
- runtime execution-order trace behavior introduced in `1.0.2`.

## One-Sentence Objective

Make RR function boundaries easier to reason about by separating simulation logic from derived-metric computation.

## Why This Version Matters

Before this patch, RR simulation and metric derivation were partially coupled in one function, which made the call graph less consistent with FCFS/SJF and harder to read.

This version aligns RR to the same orchestration pattern used elsewhere in the codebase, improving maintainability and reducing cognitive overhead for reviews and future edits.

## Plan A / Plan B

### Plan A

Perform a minimal refactor in place: rename the function, move only call boundaries, keep behavior unchanged.

### Plan B

Perform a broader scheduler-interface redesign across all four algorithms.

Plan A was used to preserve low risk and tight scope.

## System View

`simulate_rr` (dispatch and waiting-time simulation) -> `compute_response_times` -> `compute_turnaround_times` -> `compute_averages` -> `print_table`

## Artifact Map

Primary files in this version:

- `cmsc-125-cpu-scheduling/california_rr.c`
- `README.md`
- `CHANGELOG.md`
- `docs/version-1.0.3-docs.md`

## Guided Walkthrough

## 1) Responsibility split

`simulate_rr(...)` now owns only stateful RR simulation concerns:

- remaining burst times,
- dispatch cycle progression,
- first-dispatch capture,
- waiting-time completion,
- execution-order recording.

It no longer computes response/turnaround metrics directly.

## 2) Main-flow orchestration

`main()` now reads as a linear data pipeline:

1. run simulation,
2. derive response times from first dispatch,
3. derive turnaround times from waiting+burst,
4. compute averages,
5. print outputs.

This mirrors the FCFS/SJF layout and makes stage boundaries explicit.

## 3) API boundary cleanup

The refactor removed unused responsibilities from the simulator parameters (`rt`/`tat`) and introduced an explicit `first_dispatch` array at call site, clarifying data ownership.

## Validation Evidence

Compilation gate:

```powershell
gcc -Wall -Wextra -pedantic california_rr.c -o $env:TEMP\california_rr_refactor.exe
```

Result: clean compile.

Runtime check on the default dataset confirms unchanged output:

```text
Execution Order: P1, P2, P3, P4, P5, P1, P2, P3, P4, P1, P3
Average WT: 16.00
Average RT: 6.00
Average TAT: 21.60
```

## Pitfalls and Debugging Guidance

### 1) Partial signature updates

If function signatures are refactored, update both prototypes and call sites together.

### 2) Hidden coupling regressions

If a simulator function starts calling derived-metric helpers again, call-graph clarity regresses. Keep stage boundaries explicit in `main()`.

### 3) Output-only checks

Matching output values are necessary but not sufficient; verify call-graph shape and parameter intent during review.

## Practice Task

Add a short comment block above `simulate_rr(...)` that defines its input/output contract, then run the same compile gate to ensure no behavioral drift.

## Self-Check

You are aligned with `1.0.3` if:

- RR uses `simulate_rr(...)` as the simulation entry point,
- `main()` performs post-processing in explicit helper calls,
- `README.md` points to `docs/version-1.0.3-docs.md`,
- `CHANGELOG.md` top entry is `1.0.3`.

## Next Steps

1. Optionally add a lightweight automated output check script for all schedulers.
2. Keep future RR changes inside the simulation stage unless the change is truly metric-derivation logic.
