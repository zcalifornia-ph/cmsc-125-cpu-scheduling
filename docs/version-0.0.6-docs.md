# Version 0.0.6 Documentation

## Title

Unit `U-F` / Bolt `B-F1` completion: screenshot generation, validation evidence, and learner approval.

## Quick Diagnostic Read

Version `0.0.6` advances Unit F from pending to partially completed.

What changed:

- four labeled screenshots were generated from current runs of FCFS, SJF, RR, and Priority
- Bolt `B-F1` was validated against `AC-F1.1`, `AC-F1.2`, and `AC-F1.3`
- learner review for `B-F1` was approved, unblocking `B-F2`

What is still pending:

- Bolt `B-F2` comparative write-up (`artifacts/writeup.md`)
- Bolt `B-F3` PDF assembly (`california_rfm.pdf`)
- Unit `U-G` packaging (`california.zip`)

## One-Sentence Objective

Capture a reproducible, evidence-backed screenshot baseline so Unit F write-up and PDF assembly can proceed without rework.

## Why This Version Matters

Before `0.0.6`, Unit F had no screenshot artifacts and could not move into comparative write-up/PDF assembly confidently.

This version establishes:

- concrete screenshot deliverables in the required naming order
- command-level evidence of compile and run provenance
- traceability linkage from story `US-F1` to test `T-F1`, deploy check `DC-4`, and ops signal `OS-3`

## Plan A / Plan B

### Plan A

Scripted screenshot rendering from captured stdout with a fixed monospaced visual profile.

### Plan B

Manual terminal screenshots with ad-hoc window settings.

Plan B was not used because it increases framing/legibility variance and weakens reproducibility.

## System View

At `0.0.6`, the flow for Unit F starts as:

`current .c sources` -> `compile clean` -> `run each algorithm` -> `capture stdout` -> `render labeled PNGs` -> `evidence + traceability`

This output now feeds:

- Bolt `B-F2` numeric write-up sourcing
- Bolt `B-F3` PDF assembly input order

## Artifact Map

Primary artifacts produced/updated in this version:

- `cmsc-125-cpu-scheduling/artifacts/screenshots/01_fcfs.png`
- `cmsc-125-cpu-scheduling/artifacts/screenshots/02_sjf.png`
- `cmsc-125-cpu-scheduling/artifacts/screenshots/03_rr.png`
- `cmsc-125-cpu-scheduling/artifacts/screenshots/04_prio.png`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-f/t-f1-evidence.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-f/b-f1-traceability.md`
- `cmsc-125-cpu-scheduling/REQUIREMENTS.md` (Bolt `B-F1` checklist + execution note + review approval)

## Guided Walkthrough

## 1) Source-proven runs

All four scheduler files were recompiled with `-std=c99 -Wall -Wextra` before capture to satisfy provenance expectations of `AC-F1.3`.

## 2) Labeled screenshot generation

Each run output was rendered into PNG with explicit labels:

- algorithm name
- source filename
- execution order
- full per-process table
- three averages

## 3) T-F1 evidence and traceability closeout

`T-F1` evidence was written and Unit-F traceability was updated from pending to validated, then to learner-approved after review.

## Copy-Paste Commands

From `cmsc-125-cpu-scheduling/` project target:

```powershell
gcc -std=c99 -Wall -Wextra california_fcfs.c -o california_fcfs
gcc -std=c99 -Wall -Wextra california_sjf.c -o california_sjf
gcc -std=c99 -Wall -Wextra california_rr.c -o california_rr
gcc -std=c99 -Wall -Wextra california_prio.c -o california_prio

.\california_fcfs.exe
.\california_sjf.exe
.\california_rr.exe
.\california_prio.exe
```

Screenshot openability checks:

```powershell
magick identify -format '%wx%h' artifacts/screenshots/01_fcfs.png
magick identify -format '%wx%h' artifacts/screenshots/02_sjf.png
magick identify -format '%wx%h' artifacts/screenshots/03_rr.png
magick identify -format '%wx%h' artifacts/screenshots/04_prio.png
```

## Pitfalls and Debugging Guidance

### 1) Stale binary risk

Always compile before screenshot capture; do not assume existing `.exe` files reflect current source.

### 2) Legibility drift

Keep monospaced font, high contrast, and no-wrap rendering to avoid clipped or unreadable tables.

### 3) Sequence drift

Do not proceed to `B-F2` until `B-F1` review is explicitly approved.

## Practice Task

Implement Bolt `B-F2`: write `artifacts/writeup.md` with FCFS/SJF/RR averages sourced from generated runs and mechanism-level explanations per acceptance criteria.

## Self-Check

You are aligned with `0.0.6` if:

- all four screenshot files exist with the required names
- screenshots visibly include execution order, full table, and all three averages
- `REQUIREMENTS.md` shows `B-F1` Design/Implement/Test/Docs/Review complete
- next active scope is `B-F2`, not `B-F1`

## Next Steps

1. Execute `build.task` for `U-F` / `B-F2` (comparative write-up).
2. Execute `build.task` for `U-F` / `B-F3` (PDF assembly).
3. Execute `build.task` for `U-G` / `B-G1` (submission zip).
