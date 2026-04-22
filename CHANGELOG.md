# Changelog

All notable changes to this repository will be documented in this file.

## [0.0.9] - 2026-04-23

### Added

- Added `docs/version-0.0.9-docs.md` documenting Unit `U-G` / Bolt `B-G1` submission-zip completion, verification evidence, and learner Gate E approval.
- Added Unit `U-G` Bolt `B-G1` construction artifacts (workspace AI-DLC context) under `cmsc-125-cpu-scheduling/ai-dlc-docs/`:
  - design artifacts (`design-artifacts/u-g/domain-design.md`, `design-artifacts/u-g/logical-design.md`)
  - ADR (`design-artifacts/u-g/adr/b-g1-adr.md`)
  - traceability (`traceability/u-g/b-g1-traceability.md`)
  - test evidence (`test-artifacts/u-g/t-g1-evidence.md`, `test-artifacts/u-g/t-g1-zip-listing.txt`)

### Changed

- Updated `README.md` to version `0.0.9`, linked `docs/version-0.0.9-docs.md`, and refreshed status/layout/current-state sections to reflect Unit `U-G` completion and Gate E approval.
- Updated `cmsc-125-cpu-scheduling/REQUIREMENTS.md` for Bolt `B-G1`:
  - `Design`, `Implement`, `Test`, `Docs`, and `Review` marked complete
  - execution note and Gate E status updated to record learner approval
  - section 13 "Suggested Next `.task` Invocation" remains aligned to `deploy.task` then `ops.task`
- Updated `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-g/b-g1-traceability.md` status and notes to reflect learner Gate E approval.

### For Deletion

- `cmsc-125-cpu-scheduling/california_fcfs.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_sjf.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_rr.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_prio.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.aux` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.bbl` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.blg` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.fdb_latexmk` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.fls` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.log` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.out` (LaTeX intermediate artifact)

## [0.0.8] - 2026-04-23

### Added

- Added `docs/version-0.0.8-docs.md` documenting Unit `U-F` / Bolt `B-F3` completion through a learner-owned LaTeX/BibTeX path, validation checks, and learner approval.
- Added report-source artifacts under `cmsc-125-cpu-scheduling/writeup/`:
  - `california_rfm.tex`
  - `references.bib`
  - `up-header.png`
- Added Unit `U-F` Bolt `B-F3` construction artifacts (workspace AI-DLC context) under `cmsc-125-cpu-scheduling/ai-dlc-docs/`:
  - design updates (`design-artifacts/u-f/domain-design.md`, `design-artifacts/u-f/logical-design.md`)
  - ADR update (`design-artifacts/u-f/adr/b-f3-adr.md`)
  - traceability update (`traceability/u-f/b-f3-traceability.md`)
  - test evidence (`test-artifacts/u-f/t-f3-evidence.md`)
  - page-order marker extracts (`test-artifacts/u-f/pdf-pages-latex/page-01.txt` through `page-05.txt`)

### Changed

- Updated `README.md` to version `0.0.8`, linked `docs/version-0.0.8-docs.md`, and refreshed status/layout text to reflect Unit `U-F` Gate-D approval and the learner-owned LaTeX report path.
- Updated `README.md` repository layout to include `writeup/up-header.png` and remove the root-level `california_rfm.pdf` entry so the tree mirrors the current workspace state.
- Updated `cmsc-125-cpu-scheduling/REQUIREMENTS.md` for Bolt `B-F3`:
  - `Design`, `Implement`, `Test`, `Docs`, and `Review` marked complete
  - execution note updated to record learner-owned LaTeX output and learner approval
  - Gate D status updated to include Unit `U-F` approval
- Updated `cmsc-125-cpu-scheduling/writeup/references.bib` so repeated-author output is no longer implied by em dash shorthand, using explicit author metadata control for bibliography rendering.

### For Deletion

- `cmsc-125-cpu-scheduling/california_fcfs.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_sjf.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_rr.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_prio.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.aux` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.bbl` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.blg` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.fdb_latexmk` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.fls` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.log` (LaTeX intermediate artifact)
- `cmsc-125-cpu-scheduling/writeup/california_rfm.out` (LaTeX intermediate artifact)

## [0.0.7] - 2026-04-22

### Added

- Added `docs/version-0.0.7-docs.md` documenting Unit `U-F` / Bolt `B-F2` comparative write-up completion, evidence checks, and learner approval.
- Added `cmsc-125-cpu-scheduling/artifacts/writeup.md` with FCFS/SJF/RR comparative analysis using run-derived averages.
- Added Unit `U-F` Bolt `B-F2` construction artifacts (workspace AI-DLC context) under `cmsc-125-cpu-scheduling/ai-dlc-docs/`:
  - ADR: `design-artifacts/u-f/adr/b-f2-adr.md`
  - traceability: `traceability/u-f/b-f2-traceability.md`
  - test evidence: `test-artifacts/u-f/t-f2-evidence.md`

### Changed

- Updated `README.md` to version `0.0.7`, linked `docs/version-0.0.7-docs.md`, and refreshed status/layout text to show that Unit `U-F` Bolts `B-F1` and `B-F2` are complete.
- Updated `README.md` repository layout to include `artifacts/writeup.md` in the project target path.
- Updated `cmsc-125-cpu-scheduling/REQUIREMENTS.md` for Bolt `B-F2`:
  - `Design`, `Implement`, `Test`, `Docs`, and `Review` marked complete
  - execution note updated to indicate learner approval and `B-F3` unblocked

### For Deletion

- `cmsc-125-cpu-scheduling/california_fcfs.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_sjf.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_rr.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_prio.exe` (local build artifact)

## [0.0.6] - 2026-04-22

### Added

- Added `docs/version-0.0.6-docs.md` documenting Unit `U-F` / Bolt `B-F1` completion, screenshot evidence generation, learner approval, and downstream remaining work.
- Added screenshot artifacts under `cmsc-125-cpu-scheduling/artifacts/screenshots/`:
  - `01_fcfs.png`
  - `02_sjf.png`
  - `03_rr.png`
  - `04_prio.png`
- Added Unit `U-F` construction artifacts (workspace AI-DLC context) under `cmsc-125-cpu-scheduling/ai-dlc-docs/`:
  - design artifacts (`design-artifacts/u-f/`)
  - traceability (`traceability/u-f/b-f1-traceability.md`)
  - test evidence (`test-artifacts/u-f/t-f1-evidence.md`)

### Changed

- Updated `README.md` to version `0.0.6`, linked `docs/version-0.0.6-docs.md`, and refreshed status text to reflect that Bolt `B-F1` is complete and learner-approved while `B-F2/B-F3` and Unit `U-G` remain pending.
- Updated `README.md` repository layout/status sections to include the new screenshot artifact path and Unit-F progress.
- Updated `cmsc-125-cpu-scheduling/REQUIREMENTS.md` for Bolt `B-F1`:
  - `Design`, `Implement`, `Test`, `Docs`, and `Review` marked complete
  - execution note updated to indicate learner approval and `B-F2` unblocked

### For Deletion

- `cmsc-125-cpu-scheduling/california_fcfs.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_sjf.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_rr.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_prio.exe` (local build artifact)

## [0.0.5] - 2026-04-22

### Added

- Added `docs/version-0.0.5-docs.md` documenting the Unit `U-B/U-C/U-D/U-E` construction pass, verification evidence, and remaining submission gates.
- Added scheduling implementation sources under the project target path:
  - `cmsc-125-cpu-scheduling/california_fcfs.c`
  - `cmsc-125-cpu-scheduling/california_sjf.c`
  - `cmsc-125-cpu-scheduling/california_rr.c`
  - `cmsc-125-cpu-scheduling/california_prio.c`
- Added AI-DLC construction artifacts for Units `U-B` through `U-E`:
  - Unit-scoped domain/logical design files under `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-{b,c,d,e}/`
  - Unit-scoped ADRs under `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-{b,c,d,e}/adr/`
  - Unit-scoped traceability artifacts under `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-{b,c,d,e}/`
  - Unit-scoped test evidence under `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-{b,c,d,e}/`

### Changed

- Updated `README.md` to mark the repository as version `0.0.5`, point to `docs/version-0.0.5-docs.md`, and reflect that FCFS/SJF/RR/Priority source implementations now exist in the project target directory.
- Updated `README.md` repository layout and status sections to include the AI-DLC artifact tree and to mark Unit F/Unit G deliverables as the remaining gap.
- Updated `cmsc-125-cpu-scheduling/REQUIREMENTS.md` Bolt checklist state for `B-B1`, `B-C1`, `B-D1`, and `B-E1`:
  - `Design`, `Implement`, `Test`, `Docs` marked complete
  - execution notes added with compile/runtime evidence references
  - learner `Review` for Gate D intentionally left pending

### For Deletion

- `cmsc-125-cpu-scheduling/california_fcfs.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_sjf.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_rr.exe` (local build artifact)
- `cmsc-125-cpu-scheduling/california_prio.exe` (local build artifact)

## [0.0.4] - 2026-04-22

### Added

- Added `docs/version-0.0.4-docs.md` documenting the local reference-article formatting pass, README alignment, and notice-boundary updates.
- Added a formatted local article set under `docs/articles/`:
  - `docs/articles/cpu-scheduling.md`
  - `docs/articles/first-come-first-serve.md`
  - `docs/articles/priority-scheduling.md`
  - `docs/articles/round-robin.md`
  - `docs/articles/shortest-job-first.md`

### Changed

- Reformatted the five `docs/articles/*.md` files from plain text dumps into structured Markdown with headings, lists, fenced code blocks, and separated output sections where available.
- Updated `README.md` to mark the repository as version `0.0.4`, point the latest-version link at `docs/version-0.0.4-docs.md`, and surface the local formatted reference articles in both the repository layout and reference-materials sections.
- Updated `THIRD-PARTY-NOTICES.md` to clarify that `docs/articles/` contains third-party reference material and that local formatting changes for readability do not change the ownership boundary.

### For Deletion

- None.

## [0.0.3] - 2026-04-22

### Added

- Added `docs/version-0.0.3-docs.md` documenting the README redesign, template-alignment decisions, and the relationship between the README, `LICENSE.txt`, and `THIRD-PARTY-NOTICES.md`.

### Changed

- Reworked `README.md` to better follow the repository's sample README structure, including badges, a centered project hero, a screenshot banner, a table of contents, sectioned project narrative, and footer-style reference links.
- Updated `README.md` version references from `0.0.2` to `0.0.3` and pointed the "latest version notes" link at the new `docs/version-0.0.3-docs.md` artifact.
- Expanded `README.md` so the MIT license baseline and third-party notice boundary are visible in the landing page instead of being implied only by the separate root files.

### For Deletion

- None.

## [0.0.2] - 2026-04-22

### Added

- Added `LICENSE.txt` using the MIT template with project-specific copyright information.
- Added `docs/version-0.0.2-docs.md` with the rationale for selecting MIT from the local license catalog and the repository-level documentation updates that followed.

### Changed

- Updated `README.md` to mark the repository as version `0.0.2`, restore the root title/description, and document the MIT license baseline.
- Updated `THIRD-PARTY-NOTICES.md` to replace the previous proprietary-language assumption with MIT-based repository ownership terms.

### For Deletion

- None.

## [0.0.1] - 2026-04-22

### Added

- Initialized the root project documentation for the CMSC 125 CPU Scheduling repository.
- Added a repository-specific `README.md` describing the assignment objective, expected deliverables, and current repository state.
- Added `CODE_OF_CONDUCT.md`, `CONTRIBUTING.md`, and `SECURITY.md` for governance and contribution expectations.
- Added `docs/version-0.0.1-docs.md` with a detailed breakdown of the initialization changes and repository baseline.

### Changed

- Finalized repository ignore rules for local workflow-management files.
- Added conservative ignore rules for C/C++ build outputs and assignment packaging artifacts.

### For Deletion

- None.
