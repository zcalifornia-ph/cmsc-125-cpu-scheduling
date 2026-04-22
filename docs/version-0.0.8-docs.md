# Version 0.0.8 Documentation

## Title

Unit `U-F` / Bolt `B-F3` completion: learner-owned LaTeX PDF workflow, bibliography normalization, and Gate-D approval.

## Quick Diagnostic Read

Version `0.0.8` closes Unit F using a source-first write-up workflow (`.tex` + `.bib`) instead of a one-off generated PDF pipeline.

What changed:

- Bolt `B-F3` output is now maintained through `writeup/california_rfm.tex` and `writeup/references.bib`
- `references.bib` explicitly prevents repeated-author em-dash shorthand by using `IEEEtranBSTCTL`
- required screenshot order and comparative write-up sequence were revalidated from compiled output markers
- learner review for `B-F3` is approved and Unit `U-F` is now Gate-D complete

What is still pending:

- Unit `U-G` packaging (`california.zip`)

## One-Sentence Objective

Deliver a reproducible, editable, and reviewable report pipeline that preserves assignment-required page order while keeping citations explicit and stable.

## Why This Version Matters

Before `0.0.8`, Unit F had screenshots (`B-F1`) and the comparative write-up (`B-F2`) but no finalized source-of-truth report assembly format.

This version establishes:

- an auditable report source path (`.tex` + `.bib`) under versioned project files
- deterministic figure order tied to named screenshot artifacts
- explicit bibliography-author rendering behavior (no implied repeated-author shorthand)
- AI-DLC traceability updates that record learner-approved completion of `B-F3`

## Plan A / Plan B

### Plan A

Use LaTeX and BibTeX as the maintained source of truth, compile with a deterministic pass order, and preserve validation evidence in Unit-F test artifacts.

### Plan B

Assemble the PDF directly from ad-hoc markdown/office conversion without source-controlled bibliography logic.

Plan B was not used because it weakens repeatability and makes citation rendering behavior harder to validate.

## System View

At `0.0.8`, Unit F flow is:

`B-F1 screenshots + B-F2 write-up content` -> `writeup/california_rfm.tex + references.bib` -> `compiled california_rfm.pdf` -> `Gate-D review approval`

This keeps content edits and citation behavior in source files rather than hidden in binary-only editing tools.

## Artifact Map

Primary artifacts produced/updated in this version:

- `README.md` (version/status/layout alignment for `0.0.8`)
- `CHANGELOG.md` (`0.0.8` release record and cleanup candidates)
- `docs/version-0.0.8-docs.md`
- `cmsc-125-cpu-scheduling/writeup/california_rfm.tex`
- `cmsc-125-cpu-scheduling/writeup/references.bib`
- `cmsc-125-cpu-scheduling/writeup/up-header.png`
- `cmsc-125-cpu-scheduling/writeup/california_rfm.pdf`
- `cmsc-125-cpu-scheduling/REQUIREMENTS.md` (B-F3 closeout + Unit-F Gate-D status)
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-f/domain-design.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-f/logical-design.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-f/adr/b-f3-adr.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-f/b-f3-traceability.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-f/t-f3-evidence.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-f/pdf-pages-latex/page-01.txt` through `page-05.txt`

## Guided Walkthrough

## 1) LaTeX structure and styling

`writeup/california_rfm.tex` was authored to retain the report look while embedding:

- ordered screenshot pages (FCFS, SJF, RR, Priority)
- a comparative section for FCFS/SJF/RR metrics
- bibliography integration using `IEEEtran`
- stable page framing with header image and consistent figure sizing

## 2) Bibliography behavior hardening

`writeup/references.bib` includes:

- `@IEEEtranBSTCTL{rfm_bstctl, CTLdash_repeated_names = "no"}`
- explicit `author` values on each StudyTonight reference entry

This prevents bibliography output from using implied repeated-author em dash shorthand.

## 3) Validation evidence capture

Unit-F evidence captures include:

- compiled output checks (`pdfinfo`, PDF openability checks)
- extracted page markers from compiled output pages 1 through 5 to verify required ordering
- traceability and test-artifact updates linked to `US-F3`, `T-F3`, and Unit-F Gate-D approval

## Copy-Paste Commands

From `cmsc-125-cpu-scheduling/writeup/`:

```powershell
pdflatex -interaction=nonstopmode -halt-on-error california_rfm.tex
bibtex california_rfm
pdflatex -interaction=nonstopmode -halt-on-error california_rfm.tex
pdflatex -interaction=nonstopmode -halt-on-error california_rfm.tex
```

Optional page-order marker extraction from the `cmsc-125-cpu-scheduling/` target path:

```powershell
$out = "ai-dlc-docs/test-artifacts/u-f/pdf-pages-latex"
New-Item -ItemType Directory -Force $out | Out-Null
1..5 | ForEach-Object {
  $target = Join-Path $out ("page-{0:d2}.txt" -f $_)
  pdftotext -f $_ -l $_ "writeup/california_rfm.pdf" $target
}
```

## Pitfalls and Debugging Guidance

### 1) Missing asset paths in LaTeX

`up-header.png` and `../artifacts/screenshots/*.png` must resolve from `writeup/`; path mistakes fail compilation.

### 2) Bibliography not refreshing

If references do not update, rerun `bibtex` followed by two `pdflatex` passes.

### 3) Citation style regression

If repeated-author shorthand appears again, confirm `\bstctlcite{rfm_bstctl}` remains in the document preamble/body and the control entry exists in `references.bib`.

## Practice Task

Execute Unit `U-G` / Bolt `B-G1` by creating `california.zip` with exactly:

1. `california_fcfs.c`
2. `california_sjf.c`
3. `california_prio.c`
4. `california_rr.c`
5. `california_rfm.pdf`

## Self-Check

You are aligned with `0.0.8` if:

- `REQUIREMENTS.md` shows Bolt `B-F3` as review-approved
- LaTeX and BibTeX sources exist under `writeup/`
- bibliography configuration prevents implied repeated-author shorthand
- Unit F is marked Gate-D approved and Unit G is the only remaining submission unit

## Next Steps

1. Execute `build.task` for `U-G` / `B-G1` to produce `california.zip`.
2. Re-run `commit.task` after Unit `U-G` completion to release a packaging-complete version record.
