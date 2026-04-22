# Version 1.0.4 Documentation

## Title

Scheduler abstraction unification: `Process`-struct modeling and consistent process-count conventions across all policies.

## Quick Diagnostic Read

Version `1.0.4` resolves cross-file abstraction drift in scheduler implementations.

What changed:

- all four scheduler sources now model runtime state using a `Process` struct,
- Priority now uses `PROCESS_COUNT` instead of `N`,
- Priority now runs with five processes to match the repository-wide scheduler count convention.

What remained stable:

- algorithm policy behavior (FCFS/SJF/RR/Priority semantics),
- compile and run viability across all four scheduler executables.

## One-Sentence Objective

Use one defensible data model across all scheduling policies so implementation and write-up narratives stay coherent.

## Why This Version Matters

Before this patch, the repository mixed two modeling styles:

- parallel arrays in FCFS/RR,
- `Process`-struct representation in SJF/Priority.

That inconsistency made cross-policy comparisons harder to defend and increased maintenance overhead when adding fields or refactoring helper signatures.

Version `1.0.4` makes the model explicit and uniform: one process record abstraction, four scheduling policies.

## Plan A / Plan B

### Plan A

Refactor FCFS and RR to struct style, then normalize Priority constants and metric storage while keeping SJF as-is (already aligned).

### Plan B

Introduce a shared header/library to centralize struct and utility helpers.

Plan A was used to keep scope low-risk and avoid broad file-organization churn.

## System View

`Process[]` state -> policy-specific scheduling function(s) -> derived metrics (WT/RT/TAT) -> formatted output table

Applied consistently across:

- FCFS
- SJF
- RR
- Priority

## Artifact Map

Primary files in this version:

- `cmsc-125-cpu-scheduling/california_fcfs.c`
- `cmsc-125-cpu-scheduling/california_rr.c`
- `cmsc-125-cpu-scheduling/california_prio.c`
- `README.md`
- `CHANGELOG.md`
- `docs/version-1.0.4-docs.md`

## Guided Walkthrough

## 1) FCFS aligned to struct abstraction

`california_fcfs.c` now defines:

```c
typedef struct {
    int pid;
    int bt;
    int wt;
    int rt;
    int tat;
} Process;
```

All FCFS helper functions now accept `Process[]` instead of separate `pid[]`, `bt[]`, `wt[]`, `rt[]`, `tat[]` arrays.

## 2) RR aligned while preserving recent fixes

`california_rr.c` now stores mutable simulation state in struct fields:

- `remaining_bt`
- `first_dispatch`

This preserved both recent RR improvements:

- runtime-generated execution order,
- explicit post-processing staging in `main()`.

## 3) Priority normalized to shared count and state layout

`california_prio.c` now:

- uses `#define PROCESS_COUNT 5`,
- stores `wt`, `rt`, `tat` inside `Process`,
- keeps priority policy behavior intact (higher numeric priority first),
- uses five-process input so count conventions are consistent across all scheduler files.

## Validation Evidence

Compile gate used for all scheduler files:

```powershell
gcc -Wall -Wextra -pedantic california_fcfs.c -o <temp-exe>
gcc -Wall -Wextra -pedantic california_sjf.c -o <temp-exe>
gcc -Wall -Wextra -pedantic california_rr.c -o <temp-exe>
gcc -Wall -Wextra -pedantic california_prio.c -o <temp-exe>
```

Result: all four compiled successfully.

Runtime verification:

- FCFS output remained valid and deterministic for the shared 5-process dataset.
- SJF output remained valid and unchanged structurally.
- RR output retained runtime-generated execution-order trace and expected metric values.
- Priority output now reflects a 5-process priority schedule with coherent WT/RT/TAT computation.

## Pitfalls and Debugging Guidance

### 1) Dataset comparability assumptions

Priority input values changed to a 5-process set for consistency. Any old screenshots or report sections based on the 4-process run must be regenerated.

### 2) Struct-field drift

When adding new per-process metrics later, ensure every scheduler initializes and updates new fields consistently.

### 3) Signature mismatch after refactors

If you see compile errors around helper arguments, verify all call sites were migrated from array-based signatures to `Process[]`.

## Practice Task

Add a `completion_time` field to `Process` in one scheduler file, then propagate it across all four files so the abstraction remains consistent end-to-end.

## Self-Check

You are aligned with `1.0.4` if:

- each scheduler file uses a `Process` struct as the primary data model,
- Priority uses `PROCESS_COUNT` instead of `N`,
- root docs point to `docs/version-1.0.4-docs.md`,
- all four schedulers compile and execute successfully.

## Next Steps

1. Regenerate any report artifacts that assumed a 4-process Priority run.
2. Optionally extract a shared scheduler-model header if you want stronger cross-file type consistency.
