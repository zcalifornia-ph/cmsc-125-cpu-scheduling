# Version 1.0.5 Documentation

## Title

Comparative write-up analysis closure: explicit metric-link explanation and clearer policy tradeoff conclusion.

## Quick Diagnostic Read

Version `1.0.5` improves report quality by tightening the comparative analysis language in both maintained write-up sources.

What changed:

- added an explicit FCFS/SJF `ART == AWT` explanation under zero-arrival, non-preemptive assumptions,
- added a one-line cross-metric takeaway that frames SJF-vs-RR tradeoffs for interactivity contexts,
- kept Markdown and LaTeX write-up sources synchronized.

What remained stable:

- algorithm implementations and metric values,
- comparative table entries and measured averages.

## One-Sentence Objective

Close analysis gaps that cost points by making implied metric relationships and policy tradeoffs explicit to the reader.

## Why This Version Matters

The prior write-up already had correct values and basic explanations, but two high-value interpretation lines were missing:

- why FCFS/SJF show equal AWT and ART in this dataset,
- what the three-metric comparison implies for real scheduling goals (throughput vs responsiveness).

Adding these lines improves defensibility and turns a descriptive comparison into a short, decision-oriented analysis.

## Plan A / Plan B

### Plan A

Insert the two exact insight sentences into both report sources (`writeup.md` and `.tex`) and leave all numeric content unchanged.

### Plan B

Rewrite the entire comparison section with expanded prose.

Plan A was used to keep scope minimal and preserve existing validated content.

## System View

`validated metric table` -> `analysis paragraphs` -> `explicit relationship + tradeoff statements` -> `stronger grading-facing write-up`

## Artifact Map

Primary files in this version:

- `cmsc-125-cpu-scheduling/artifacts/writeup.md`
- `cmsc-125-cpu-scheduling/writeup/california_rfm.tex`
- `README.md`
- `CHANGELOG.md`
- `docs/version-1.0.5-docs.md`

## Guided Walkthrough

## 1) ART/AWT equality rationale added

In both write-up sources, a new sentence now states that FCFS and SJF have `ART == AWT` because:

- arrival time is zero for all processes,
- neither algorithm preempts,
- first dispatch occurs exactly when waiting ends.

## 2) Cross-metric takeaway added

In both write-up sources, a new concluding sentence now states:

- SJF dominates this dataset across AWT/ART/ATT as reported,
- RR still offers the best ART and is therefore appropriate when interactivity is prioritized.

## 3) Source synchronization preserved

The same analytical closure statements were applied to both Markdown and LaTeX report sources to avoid drift between documentation and final PDF source material.

## Validation Evidence

Validation checks performed:

- `git diff` confirmed the two sentences were inserted at the intended ART/ATT analysis locations in both files.
- targeted text search confirmed presence of:
  - `ART == AWT` explanation,
  - `interactivity matters` tradeoff conclusion.

No code execution or metric recomputation was required because this patch is analysis-text only.

## Pitfalls and Debugging Guidance

### 1) Markdown/LaTeX drift

When improving write-up text, always patch both `artifacts/writeup.md` and `writeup/california_rfm.tex` to keep report variants consistent.

### 2) Overwriting validated numbers

Keep metric tables unchanged during prose fixes unless new runs are intentionally performed.

### 3) Hidden analysis gaps

After writing comparisons, explicitly answer:

- why the observed values happen,
- what decision/tradeoff they imply.

## Practice Task

Add one more short sentence that explains why RR's turnaround can degrade under frequent slicing even when response time improves, then verify it stays consistent across Markdown and LaTeX sources.

## Self-Check

You are aligned with `1.0.5` if:

- both write-up sources contain the new `ART == AWT` explanation,
- both write-up sources contain the SJF-vs-RR tradeoff conclusion,
- README points to `docs/version-1.0.5-docs.md`,
- CHANGELOG top entry is `1.0.5`.

## Next Steps

1. Rebuild the PDF from `writeup/california_rfm.tex` so the final submission artifact includes the new analysis lines.
2. Optionally add one-sentence interpretation rules to your writing checklist for future scheduler comparisons.
