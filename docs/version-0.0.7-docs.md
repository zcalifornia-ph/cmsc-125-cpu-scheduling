# Version 0.0.7 Documentation

## Title

Unit `U-F` / Bolt `B-F2` completion: comparative write-up artifact, validation evidence, and learner approval.

## Quick Diagnostic Read

Version `0.0.7` advances Unit F from screenshot-only readiness to analysis-ready documentation.

What changed:

- `artifacts/writeup.md` was authored for FCFS/SJF/RR comparison
- averages were sourced from actual Unit `U-B/U-C/U-D` run evidence
- Bolt `B-F2` validation (`T-F2`) passed and learner review was approved

What is still pending:

- Bolt `B-F3` PDF assembly (`california_rfm.pdf`)
- Unit `U-G` packaging (`california.zip`)

## One-Sentence Objective

Close Unit F's analysis requirement with a reproducible, evidence-linked comparative write-up that is ready for PDF assembly.

## Why This Version Matters

Before `0.0.7`, Unit F had screenshots but no finalized comparative narrative.

This version provides:

- assignment-scoped comparison content for FCFS/SJF/RR only
- explicit mechanism-level reasoning for `AWT`, `ART`, and `ATT`
- traceable linkage from write-up values back to prior execution evidence

## Plan A / Plan B

### Plan A

Source metrics from validated run evidence files, then write a concise markdown report and verify content constraints with deterministic checks.

### Plan B

Recompute all metrics manually in the write-up.

Plan B was not used because it increases transcription and arithmetic error risk with no traceability benefit.

## System View

At `0.0.7`, Unit F flow is:

`B-F1 screenshots + U-B/U-C/U-D evidence` -> `B-F2 comparative write-up` -> `B-F3 PDF assembly`

This keeps the report grounded in actual outputs while minimizing rework in PDF assembly.

## Artifact Map

Primary artifacts produced/updated:

- `cmsc-125-cpu-scheduling/artifacts/writeup.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-f/domain-design.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-f/logical-design.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-f/adr/b-f2-adr.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-f/b-f2-traceability.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-f/t-f2-evidence.md`
- `cmsc-125-cpu-scheduling/REQUIREMENTS.md` (B-F2 checklist + execution note + review approval)

## Guided Walkthrough

## 1) Metrics sourcing from prior evidence

FCFS/SJF/RR averages were read from:

- `u-b/t-b1-evidence.md`
- `u-c/t-c1-evidence.md`
- `u-d/t-d1-evidence.md`

Values used:

- FCFS: `13.40`, `13.40`, `19.00`
- SJF: `7.60`, `7.60`, `13.20`
- RR: `16.00`, `6.00`, `21.60`

## 2) Write-up composition

`artifacts/writeup.md` includes:

- intro with explicit scope restriction (FCFS/SJF/RR only)
- three-way metrics table (`AWT`, `ART`, `ATT`)
- one mechanism paragraph each for waiting time, response time, and turnaround time

## 3) T-F2 validation and closeout

Validation checks confirmed:

- required numeric values are present verbatim
- required mechanism phrases are present
- one-page target proxy satisfied (`229` words, `19` lines)

## Copy-Paste Commands

From `cmsc-125-cpu-scheduling/` target path:

```powershell
$files=@(
  @{Algo='FCFS'; Path='ai-dlc-docs/test-artifacts/u-b/t-b1-evidence.md'},
  @{Algo='SJF'; Path='ai-dlc-docs/test-artifacts/u-c/t-c1-evidence.md'},
  @{Algo='RR'; Path='ai-dlc-docs/test-artifacts/u-d/t-d1-evidence.md'}
)
foreach($f in $files){
  $text = Get-Content -Raw $f.Path
  $awt = [regex]::Match($text,'Average WT:\s*([0-9]+\.[0-9]{2})').Groups[1].Value
  $art = [regex]::Match($text,'Average RT:\s*([0-9]+\.[0-9]{2})').Groups[1].Value
  $att = [regex]::Match($text,'Average TAT:\s*([0-9]+\.[0-9]{2})').Groups[1].Value
  "{0} AWT={1} ART={2} ATT={3}" -f $f.Algo,$awt,$art,$att
}
```

```powershell
$p='artifacts/writeup.md'
$text=Get-Content -Raw $p
([regex]::Matches($text,'\b[\w\-\*\(\)]+\b')).Count
(Get-Content $p).Count
```

## Pitfalls and Debugging Guidance

### 1) Scope drift

Do not include Priority in the three-way comparison table for `US-F2`.

### 2) Value provenance drift

Use run-evidence artifacts as the source of numeric claims, not article text.

### 3) Length overflow before PDF

Keep write-up compact so the rendered PDF section remains under one page.

## Practice Task

Execute Bolt `B-F3` by assembling `california_rfm.pdf` in the required page order:

1. FCFS screenshot
2. SJF screenshot
3. RR screenshot
4. Priority screenshot
5. comparative write-up

## Self-Check

You are aligned with `0.0.7` if:

- `artifacts/writeup.md` contains FCFS/SJF/RR table values exactly
- all three required mechanism explanations are present
- `REQUIREMENTS.md` marks `B-F2` review as approved
- next active scope is `B-F3`

## Next Steps

1. Execute `build.task` for `U-F` / `B-F3` (assemble and validate `california_rfm.pdf`).
2. Execute `build.task` for `U-G` / `B-G1` (package `california.zip`).
3. Run `commit.task` again after `B-F3`/`B-G1` to finalize submission-stage docs.
