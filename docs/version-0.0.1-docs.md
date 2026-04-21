# Version 0.0.1 Documentation

## Title

Initial repository documentation and governance bootstrap for the CMSC 125 CPU Scheduling assignment.

## Quick Diagnostic Read

This version establishes the repository baseline rather than the scheduling implementations themselves.

What is now in place:

- a project-specific root `README.md`
- a root `CHANGELOG.md` with the initial release entry
- root governance files for conduct, contribution, and security
- repository ignore rules tailored to local workflow files and expected C/C++ build artifacts

What is not yet in place:

- the four scheduling source files
- the final comparison PDF
- the packaged ZIP submission

## One-Sentence Objective

Turn an almost-empty academic repository into a usable, documented project shell that clearly states the assignment scope, deliverables, and collaboration rules before implementation begins.

## Why This Version Matters

Without a clean repository baseline, later work becomes messy quickly:

- filenames and deliverables are easy to misinterpret
- generated artifacts can pollute version control
- contribution and reporting expectations remain unclear
- future commits have no versioned documentation trail

Version `0.0.1` fixes that by making the repository legible before the algorithm implementations are added.

## Plan A / Plan B

### Plan A

Use this repository as the working assignment repo:

1. add the four algorithm source files
2. compile and run each one with your chosen dataset
3. produce the report PDF
4. keep `README.md` and `CHANGELOG.md` updated as the implementation lands

### Plan B

Use this repository first as a documentation shell:

1. finalize the naming scheme and dataset choices
2. draft the report structure
3. add the source files only after the documentation baseline is accepted

Plan A is usually better unless you are still clarifying the assignment details.

## System View

At `0.0.1`, the repository is split into three practical layers:

- public root documentation:
  `README.md`, `CHANGELOG.md`, `CODE_OF_CONDUCT.md`, `CONTRIBUTING.md`, `SECURITY.md`
- supporting project assets:
  `repo/images/project_screen.png`, `THIRD-PARTY-NOTICES.md`
- internal/local workflow support:
  local agent and tool metadata kept out of normal commits through the repository ignore rules

The main point is separation:

- public-facing docs explain the assignment
- local workflow files stay local
- future implementation files remain free to follow the assignment naming convention

## Artifact Map

Files created or finalized for this version:

- `README.md`
- `CHANGELOG.md`
- `CODE_OF_CONDUCT.md`
- `CONTRIBUTING.md`
- `SECURITY.md`
- the root ignore-rules file
- `docs/version-0.0.1-docs.md`

Existing repository assets referenced by the docs:

- `repo/images/project_screen.png`
- `THIRD-PARTY-NOTICES.md`

## Guided Walkthrough

## 1) Root README

`README.md` now explains:

- what the assignment is
- which algorithms are required
- what outputs are expected
- suggested filenames
- how to compile and run basic C/C++ files on Windows PowerShell

This is the main onboarding file for the repository.

## 2) Root CHANGELOG

`CHANGELOG.md` now records version `0.0.1` as the initialization milestone.

That gives future changes a clean place to record:

- implementation progress
- report completion
- packaging/submission changes
- cleanup candidates

## 3) Governance Documents

Three root governance files now exist:

- `CODE_OF_CONDUCT.md`
- `CONTRIBUTING.md`
- `SECURITY.md`

For a small academic repository, these are lightweight but still useful because they clarify:

- expected collaboration behavior
- academic-integrity expectations
- how security or correctness issues should be reported

## 4) Ignore Rules

The root ignore rules were finalized to ignore:

- local workflow-management files
- local environment/secrets files
- common C/C++ compiler outputs
- packaged submission artifacts such as ZIP files and the report PDF

That keeps future commits cleaner when algorithm executables and archives start appearing locally.

## Copy-Paste Commands

Check the current repository state:

```powershell
git status --short
```

Stage only the initialization docs work:

```powershell
git add README.md CHANGELOG.md CODE_OF_CONDUCT.md CONTRIBUTING.md SECURITY.md docs/version-0.0.1-docs.md
```

Review the staged result:

```powershell
git diff --cached
```

## Pitfalls and Debugging Guidance

### 1) Untracked files are not always part of the intended commit

This repository currently has other untracked items.
Do not blindly commit everything unless you have verified those files belong in the same change.

### 2) README can drift from actual repo contents

If you later add the four scheduling source files or the PDF, update `README.md` and `CHANGELOG.md` together.

### 3) Ignore rules can hide files you meant to keep

Because the report PDF and ZIP are ignored, confirm whether you want them tracked before relying on `git add .`.

## Practice Task

Add one actual algorithm file, for example `california_fcfs.c`, then update:

- `README.md` to mention that one implementation is now present
- `CHANGELOG.md` with the new version entry for that implementation step

## Self-Check

You are done with the `0.0.1` baseline if:

- root docs explain the assignment accurately
- the repository has a versioned changelog
- contribution/security/conduct expectations are present
- generated local artifacts are ignored conservatively
- the repo is ready for the first real scheduling implementation commit

## Next Steps

1. Add the four scheduling source files required by the assignment.
2. Use one shared dataset for FCFS, SJF, and RR.
3. Capture labeled execution screenshots for the report.
4. Write the metric comparison section for waiting, response, and turnaround time.
5. Create the next changelog entry when implementation starts.
