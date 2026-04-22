# Version 1.0.2 Documentation

## Title

Round Robin execution-order correctness patch: remove hardcoded output and emit data-driven dispatch order.

## Quick Diagnostic Read

Version `1.0.2` addresses a correctness smell in `california_rr.c`:

- previous behavior printed a fixed execution-order literal that only matched one burst-time dataset,
- new behavior builds execution order during simulation by appending each dispatched PID at runtime.

What changed:

- added `EXEC_ORDER_SIZE` and a bounded `exec_order` buffer,
- updated `compute_waiting_times(...)` to accept `pid` and `exec_order` output parameters,
- appended `P<id>` tokens in the RR dispatch branch using `snprintf`,
- updated `print_table(...)` to print computed `exec_order`,
- updated `main()` to allocate/pipeline the execution-order buffer.

What remains:

- no new assignment blockers; this is a targeted correctness and observability fix.

## One-Sentence Objective

Ensure Round Robin's printed execution order always reflects the actual dispatch sequence for the current dataset.

## Why This Version Matters

For CPU scheduling outputs, execution order is a primary observable behavior (Gantt-like trace). A hardcoded order can silently mislead when the dataset changes, even if waiting/turnaround metrics still compute correctly.

This patch aligns the reported order with algorithm state transitions and makes output trustworthy across datasets.

## Plan A / Plan B

### Plan A

Implement minimal in-code tracing at each RR dispatch and keep the rest of the metric logic unchanged.

### Plan B

Refactor RR into a generalized event-trace model across all schedulers.

Plan A was used to keep risk low and scope tightly bounded to the identified bug.

## System View

`RR loop dispatch events` -> `append PID to exec_order buffer` -> `print_table(exec_order)` -> `accurate execution-order output`

## Artifact Map

Primary files in this version:

- `cmsc-125-cpu-scheduling/california_rr.c`
- `README.md`
- `CHANGELOG.md`
- `docs/version-1.0.2-docs.md`

## Guided Walkthrough

## 1) Root cause area

`print_table(...)` previously contained a fixed `printf("Execution Order: ...")` literal. That output was disconnected from simulation state.

## 2) Minimal repair

`compute_waiting_times(...)` now accepts:

- `const int pid[]`
- `char exec_order[]`
- `size_t exec_order_size`

Inside the dispatch branch, each scheduled process appends `P<id>` with delimiter handling:

- first token has no leading comma,
- subsequent tokens use `", "`,
- writes are bounded with `snprintf` and guarded against overflow.

## 3) Output path update

`print_table(...)` now receives `const char exec_order[]` and prints that string directly.

`main()` allocates `char exec_order[EXEC_ORDER_SIZE]` and passes it through the existing compute/print flow.

## Validation Evidence

Compilation gate:

```powershell
gcc -Wall -Wextra -pedantic california_rr.c -o $env:TEMP\california_rr_warnings.exe
```

Result: clean compile (no warnings).

Default dataset run (`BT={8,4,9,5,2}`) output includes:

```text
Execution Order: P1, P2, P3, P4, P5, P1, P2, P3, P4, P1, P3
```

Alternate dataset run (`BT={3,7,1,6,4}`) output includes:

```text
Execution Order: P1, P2, P3, P4, P5, P2, P4, P5, P2
```

The changed sequence on alternate input confirms execution order is now data-driven, not hardcoded.

## Pitfalls and Debugging Guidance

### 1) Buffer sizing assumptions

If process count or dispatch count grows, increase `EXEC_ORDER_SIZE` or move to dynamic allocation.

### 2) Signature drift

When changing `compute_waiting_times(...)`, ensure all call sites are updated together (`main` in this file today).

### 3) False confidence from one dataset

Always run at least one alternate burst-time set when validating scheduler output formatting logic.

## Practice Task

Run RR with three distinct burst-time sets and verify:

1. execution order changes when inputs change,
2. waiting/response/turnaround outputs remain coherent,
3. output formatting remains stable (`P#` comma-separated list).

## Self-Check

You are aligned with `1.0.2` if:

- `california_rr.c` has no hardcoded execution-order literal,
- execution order is assembled during RR dispatch,
- README points to `docs/version-1.0.2-docs.md`,
- CHANGELOG top entry is `1.0.2`.

## Next Steps

1. Optionally mirror data-driven execution-order traces in FCFS/SJF/Priority for consistency.
2. Add small output regression tests if a C test harness is introduced later.
