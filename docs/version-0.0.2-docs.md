# Version 0.0.2 Documentation

## Title

Repository license selection and public-notice alignment for the CMSC 125 CPU Scheduling assignment.

## Quick Diagnostic Read

This version does not add algorithm implementations yet.
It establishes the legal baseline for repository-owned material now that the repository is public.

What changed in `0.0.2`:

- selected an open-source license from the local license catalog
- created `LICENSE.txt` at the repository root
- updated the README to document the license baseline
- corrected `THIRD-PARTY-NOTICES.md`, which previously described the repo as proprietary

What did not change:

- the project scope
- the assignment requirements
- the current absence of the four scheduling source files and final PDF

## One-Sentence Objective

Choose a coherent license for this public academic code repository and update the public-facing documentation so the repository no longer carries conflicting ownership terms.

## Why This Version Matters

Before this version, the repository had a public codebase but no root license file, and `THIRD-PARTY-NOTICES.md` still described the repository as proprietary.

That is a poor state for a public repo because it creates ambiguity about:

- whether others may reuse or study the code
- whether repository-owned material is open or restricted
- how third-party license texts in the workspace should be interpreted

Version `0.0.2` fixes that ambiguity.

## Plan A / Plan B

### Plan A

Use a standard open-source software license for repository-owned code and documentation.

This is the best fit when:

- the repository is public
- the code is educational or portfolio-oriented
- there is no stated commercial licensing model to preserve

### Plan B

Use a source-available license to restrict some forms of reuse.

This is usually more appropriate when:

- the repository backs a commercial product
- the maintainer wants public source visibility without broad reuse rights
- competitive-use limits are intentional and clearly justified

For this repository, Plan A is the better fit.

## License Selection Rationale

The starting templates reviewed came from the local license catalog described in the repository tooling:

- open-source templates such as MIT, Apache-2.0, and BSD-3-Clause
- source-available templates such as BSL, FSL, ELv2, RSALv2, and PolyForm variants
- closed/proprietary templates from the closed-source catalog

MIT was selected as the starting template because it best matches the current project shape:

- it is simple and widely understood
- it is appropriate for a small educational C/C++ repository
- it does not impose source-available or proprietary restrictions that the project metadata does not justify
- it avoids adding unnecessary licensing complexity before the actual algorithm implementations are even present

Apache-2.0 and BSD-3-Clause would also have been defensible open-source choices, but MIT is the lightest-weight fit here.

## System View

After `0.0.2`, the repository has a cleaner public-ownership model:

- `LICENSE.txt` defines the license for repository-owned material
- `README.md` summarizes the chosen license for readers
- `THIRD-PARTY-NOTICES.md` distinguishes repo-owned material from bundled third-party notices and reference texts
- the local license catalog remains reference material only, not the active repo license

This separation matters because the workspace contains many third-party license texts for tooling and reference purposes.

## Artifact Map

Files added or updated for this version:

- `LICENSE.txt`
- `README.md`
- `CHANGELOG.md`
- `THIRD-PARTY-NOTICES.md`
- `docs/version-0.0.2-docs.md`

Supporting context used for the decision:

- the project metadata in the local initialization config
- the local license catalog and manifest described in the repository tooling

## Guided Walkthrough

## 1) Choosing Open Source vs Source Available

The project metadata points to:

- a public GitHub repository
- an individual academic assignment
- a small C/C++ codebase
- no commercial productization terms

That makes an open-source license a better default than source-available or proprietary terms.

## 2) Choosing MIT Specifically

MIT was chosen over the other reviewed open-source templates because:

- it is brief and unambiguous
- it is common for student and small personal repositories
- it minimizes legal overhead while still granting broad reuse rights with attribution

## 3) Root License File

`LICENSE.txt` now contains the MIT text with project-specific ownership details:

- year: `2026`
- copyright holder: `Zildjian E. California`

## 4) README Alignment

`README.md` now:

- identifies the repository as version `0.0.2`
- restores the title and short description at the top
- states that repository-owned material is under the MIT License
- points readers to `LICENSE.txt`

## 5) Third-Party Notice Alignment

`THIRD-PARTY-NOTICES.md` previously described the repository as proprietary.
That wording conflicted with the new root license decision.

It now correctly states that:

- repository-owned material is under MIT
- bundled third-party notices remain governed by their own terms
- the presence of reference license texts does not relicense the repository as a whole

## Copy-Paste Commands

Review only the license-related doc changes:

```powershell
git diff -- LICENSE.txt README.md CHANGELOG.md THIRD-PARTY-NOTICES.md docs/version-0.0.2-docs.md
```

Stage the license baseline update:

```powershell
git add LICENSE.txt README.md CHANGELOG.md THIRD-PARTY-NOTICES.md docs/version-0.0.2-docs.md
```

Confirm the staged set:

```powershell
git diff --cached
```

## Pitfalls and Debugging Guidance

### 1) Public repo without a license is still ambiguous

Public visibility does not automatically grant reuse rights.
The root license file is what clarifies the permissions.

### 2) Third-party notice files can drift out of sync

If you change the repository license again later, update `THIRD-PARTY-NOTICES.md` in the same change.

### 3) Internal license catalogs are not the active license

Bundled template or reference licenses in the workspace do not apply automatically.
Only the chosen root license file governs repository-owned material.

## Practice Task

If you later decide MIT is too permissive, compare it against `Apache-2.0` and `BSD-3-Clause` and write a short note explaining:

- what practical rights change for users
- whether a patent grant matters for this project
- whether the added complexity is justified

## Self-Check

You are done with `0.0.2` if:

- `LICENSE.txt` exists at the repository root
- README and third-party notices agree on the repository ownership terms
- the changelog records the license decision as its own versioned step
- the public docs no longer imply proprietary terms for repository-owned code

## Next Steps

1. Add the four required scheduling source files.
2. Keep future code files compatible with the MIT notice structure if you later add per-file headers.
3. Update the changelog again when the first algorithm implementation lands.
