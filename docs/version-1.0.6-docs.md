# Version 1.0.6 Documentation

## Title

Scheduler minor-polish pass: output-label consistency, RR print symmetry, and explicit deterministic sort tie-break notes.

## Quick Diagnostic Read

Version `1.0.6` is a readability/consistency release for scheduler source code and output formatting.

What changed:

- unified execution-order label casing to `Execution Order` in SJF,
- moved RR average-printing into `print_table(...)` to match other schedulers,
- added one-line comments in SJF/Priority sorts explaining PID tie-break intent.

What remained stable:

- scheduling policy logic and metrics,
- process datasets and run outcomes.

## One-Sentence Objective

Remove small cross-file inconsistencies that distract reviewers and graders without changing scheduler behavior.

## Why This Version Matters

Minor inconsistencies can cost clarity points even when algorithm logic is correct. Before this patch:

- SJF used `Execution order` while others used `Execution Order`,
- RR printed averages in `main()` while peers printed them in `print_table(...)`,
- tie-break logic existed but lacked explicit rationale comments.

This patch harmonizes those details and makes intent easier to verify quickly.

## Plan A / Plan B

### Plan A

Apply targeted edits only in affected scheduler files plus release docs.

### Plan B

Delay polish and defer to a larger formatting/refactor batch.

Plan A was used to keep changes small, auditable, and immediately useful for grading/readability.

## System View

`scheduler source polish` -> `consistent output headers + table-print ownership + documented tie-breaks` -> `cleaner review and report alignment`

## Artifact Map

Primary files in this version:

- `cmsc-125-cpu-scheduling/california_sjf.c`
- `cmsc-125-cpu-scheduling/california_rr.c`
- `cmsc-125-cpu-scheduling/california_prio.c`
- `README.md`
- `CHANGELOG.md`
- `docs/version-1.0.6-docs.md`

## Guided Walkthrough

## 1) Execution-order label consistency

SJF output header was updated from:

```text
Execution order:
```

to:

```text
Execution Order:
```

so all schedulers use the same casing.

## 2) RR output responsibility symmetry

RR previously printed averages from `main()` after calling `print_table(...)`.

Now RR `print_table(...)` receives `avg_wt`, `avg_rt`, and `avg_tat` and prints all table-related output, matching FCFS/SJF/Priority conventions.

## 3) Tie-break intent comments

One-line comments were added before tie-break conditions in SJF and Priority sorts:

```c
/* Stable tie-break by PID for deterministic output. */
```

This documents why PID ordering appears in equal-key sort branches.

## Validation Evidence

Validation run:

```powershell
gcc -Wall -Wextra -pedantic california_fcfs.c -o <temp-exe>
gcc -Wall -Wextra -pedantic california_sjf.c -o <temp-exe>
gcc -Wall -Wextra -pedantic california_rr.c -o <temp-exe>
gcc -Wall -Wextra -pedantic california_prio.c -o <temp-exe>
```

Result: all files compiled.

Execution checks:

- SJF now prints `Execution Order`.
- RR still prints the same metrics, now emitted from `print_table(...)`.
- Priority/SJF behavior unchanged; comments clarify deterministic tie-break strategy.

## Pitfalls and Debugging Guidance

### 1) Cosmetic-only assumptions

Even polish changes should be compiled and run, because signature edits (like RR `print_table(...)`) can introduce regressions if call sites are missed.

### 2) Output-text drift

If screenshots or report snippets depend on exact stdout labels, refresh artifacts after casing changes.

### 3) Comment decay

If tie-break policy changes later, update comments immediately to avoid misleading explanations.

## Practice Task

Search all scheduler files for user-facing output labels and ensure formatting, punctuation, and casing follow one shared pattern.

## Self-Check

You are aligned with `1.0.6` if:

- all scheduler outputs use `Execution Order`,
- RR averages are printed inside `print_table(...)`,
- SJF/Priority tie-break comments are present,
- root docs point to `docs/version-1.0.6-docs.md`.

## Next Steps

1. Regenerate any output screenshots that include the updated SJF execution-order header.
2. Optionally add a lightweight stdout snapshot check to catch future formatting drift.
