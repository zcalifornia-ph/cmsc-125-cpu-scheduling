# Version 0.0.5 Documentation

## Title

Parallel AI-DLC construction pass for Unit `U-B/U-C/U-D/U-E` scheduling implementations and evidence artifacts.

## Quick Diagnostic Read

Version `0.0.5` is the first implementation-heavy milestone for this repository.

What changed:

- four required scheduling `.c` files were implemented under `cmsc-125-cpu-scheduling/`
- Unit-scoped design, ADR, traceability, and test-evidence artifacts were added for `U-B`, `U-C`, `U-D`, and `U-E`
- `REQUIREMENTS.md` in the project target was updated to mark `Design/Implement/Test/Docs` complete for bolts `B-B1/B-C1/B-D1/B-E1`

What is still pending:

- learner Gate D review sign-off for Units `U-B/U-C/U-D/U-E`
- Unit F output artifacts (screenshots and report PDF)
- Unit G packaging artifact (`california.zip`)

## One-Sentence Objective

Capture the transition from documentation-only setup into validated scheduling implementations with persisted AI-DLC construction traceability.

## Why This Version Matters

Before `0.0.5`, the repository had requirements and reference documents but did not yet carry the core algorithm implementations.

This version closes that gap by producing:

- executable C implementations for FCFS, SJF, Round Robin, and Priority
- evidence-bearing test artifacts for each implemented unit
- synchronized requirement checklist updates tied to evidence locations

That gives the project a concrete base for finishing Unit F (screenshots/report) and Unit G (submission zip).

## Plan A / Plan B

### Plan A

Use AI-DLC `build.task` per bolt, persist design + traceability artifacts, validate against `INCEPTION.md`, then update requirement checklist states.

### Plan B

Write only the `.c` files and skip construction artifacts.

Plan B is faster short-term but was rejected because it weakens traceability and makes Gate D validation harder.

## System View

At `0.0.5`, the project now has a two-layer structure:

- repository-level governance/docs at root (`README.md`, `CHANGELOG.md`, root policy files)
- implementation target at `cmsc-125-cpu-scheduling/` containing code and AI-DLC artifact trees

Validation links now flow from:

`REQUIREMENTS.md` -> `INCEPTION.md` expected values -> per-unit test evidence -> per-unit traceability notes.

## Artifact Map

Primary implementation files:

- `cmsc-125-cpu-scheduling/california_fcfs.c`
- `cmsc-125-cpu-scheduling/california_sjf.c`
- `cmsc-125-cpu-scheduling/california_rr.c`
- `cmsc-125-cpu-scheduling/california_prio.c`

Unit artifact roots:

- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-b/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-c/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-d/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-e/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-b/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-c/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-d/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-e/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-b/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-c/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-d/`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-e/`

Requirements checkpoint:

- `cmsc-125-cpu-scheduling/REQUIREMENTS.md`

## Guided Walkthrough

## 1) FCFS, SJF, RR, and Priority code completion

Each algorithm now has a standalone C99 implementation with deterministic output formatting and averages.

## 2) Unit-specific design persistence

For each implemented unit (`U-B` through `U-E`), domain design, logical design, and one ADR were persisted before/alongside validation.

## 3) Evidence-first validation

Compile and runtime evidence were captured into per-unit test artifacts and linked from per-unit traceability files.

## 4) Requirements state synchronization

Bolt checklists were updated only after validation, with learner review kept pending as required by Gate D.

## Copy-Paste Commands

Compile and run all implemented algorithms from the project target directory:

```powershell
cd d:\Programming\Repositories\cmsc-125-cpu-scheduling\cmsc-125-cpu-scheduling
gcc -std=c99 -Wall -Wextra california_fcfs.c -o california_fcfs.exe
gcc -std=c99 -Wall -Wextra california_sjf.c -o california_sjf.exe
gcc -std=c99 -Wall -Wextra california_rr.c -o california_rr.exe
gcc -std=c99 -Wall -Wextra california_prio.c -o california_prio.exe
.\california_fcfs.exe
.\california_sjf.exe
.\california_rr.exe
.\california_prio.exe
```

## Pitfalls and Debugging Guidance

### 1) Gate confusion

Do not mark learner review complete unless Gate D sign-off was actually performed.

### 2) Dataset drift

FCFS/SJF/RR must keep the shared dataset contract from Unit A; Priority uses its own dataset.

### 3) Build artifacts in repo

Local `.exe` outputs are build artifacts. Keep them listed under changelog `For Deletion` until cleanup is explicitly approved.

## Practice Task

Complete Unit F Bolt `B-F1` by generating the four required screenshots, then verify legibility and table completeness before moving to write-up/PDF assembly.

## Self-Check

You are aligned with `0.0.5` if:

- all four `.c` programs compile with `-Wall -Wextra`
- runtime averages match `INCEPTION.md` section 6 values
- unit traceability and test evidence files exist for `u-b/u-c/u-d/u-e`
- `REQUIREMENTS.md` shows completed implementation subtasks and pending learner review

## Next Steps

1. Perform Gate D learner review for Units `U-B/U-C/U-D/U-E`.
2. Execute Unit F (screenshots -> write-up -> PDF).
3. Execute Unit G (`california.zip` packaging) and deployment checks `DC-1` through `DC-5`.
