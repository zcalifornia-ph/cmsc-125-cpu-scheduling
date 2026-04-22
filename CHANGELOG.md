# Changelog

All notable changes to this repository will be documented in this file.

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
