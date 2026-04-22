# Version 0.0.9 Documentation

## Title

Unit `U-G` / Bolt `B-G1` completion: submission zip packaging proof, traceability closeout, and learner Gate E approval.

## Quick Diagnostic Read

Version `0.0.9` closes the core assignment packaging step by producing and validating `california.zip` with the exact five-file flat structure.

What changed:

- `california.zip` was generated using an explicit allowlist (`california_fcfs.c`, `california_sjf.c`, `california_prio.c`, `california_rr.c`, `california_rfm.pdf`)
- `T-G1` evidence confirms exact entry count (`5`) and exact entry names
- Unit `U-G` AI-DLC construction artifacts were added (domain/logical design, ADR, traceability, test evidence)
- Bolt `B-G1` review and Gate E were learner-approved

What remains:

- optional downstream lifecycle tasks (`deploy.task`, then `ops.task`) for extended handoff/runbook operations context

## One-Sentence Objective

Finalize submission readiness by packaging exactly the required deliverables into `california.zip` and documenting deterministic validation evidence.

## Why This Version Matters

Before `0.0.9`, all algorithm and report artifacts were complete, but the assignment's final packaging contract was still open.

This version provides:

- deterministic packaging flow using a strict allowlist
- validation evidence for archive name, entry count, and entry-name exactness
- AI-DLC traceability linkage from story `US-G1` through `T-G1` and Gate E readiness checks

## Plan A / Plan B

### Plan A

Use PowerShell `Compress-Archive` with explicit paths, then validate with `tar -tf` and `.NET ZipFile`.

### Plan B

Manual zip assembly in file explorer.

Plan B was not used because it increases accidental inclusion/exclusion risk and weakens repeatable evidence capture.

## System View

At `0.0.9`, late-phase submission flow is:

`U-B/U-C/U-D/U-E code + U-F report` -> `B-G1 allowlist packaging` -> `T-G1 evidence` -> `Gate E approval`

This turns the workflow from "artifact-ready" to "submission-package-ready."

## Artifact Map

Primary artifacts produced/updated:

- `README.md` (version/status/current-state updates for `0.0.9`)
- `CHANGELOG.md` (`0.0.9` release record and cleanup candidates)
- `docs/version-0.0.9-docs.md`
- `cmsc-125-cpu-scheduling/california.zip`
- `cmsc-125-cpu-scheduling/REQUIREMENTS.md` (Bolt `B-G1` completion + Gate E approval status)
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-g/domain-design.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-g/logical-design.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/design-artifacts/u-g/adr/b-g1-adr.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/traceability/u-g/b-g1-traceability.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-g/t-g1-evidence.md`
- `cmsc-125-cpu-scheduling/ai-dlc-docs/test-artifacts/u-g/t-g1-zip-listing.txt`

## Guided Walkthrough

## 1) Packaging contract enforcement

The archive was created from an explicit five-file list, avoiding wildcard or folder-based zipping so extra files (for example `.exe` binaries) are not captured.

## 2) Validation evidence strategy

Validation used two independent checks:

- `tar -tf california.zip` for ordered listing visibility
- `.NET ZipFile` enumeration for exact entry count and full-name checks

This compensates for environments where `unzip -l` is unavailable.

## 3) Traceability and gate alignment

Unit `U-G` artifacts link:

- story `US-G1`
- test `T-G1`
- deploy checks `DC-1`, `DC-2`, `DC-5`
- ops signal `OS-2`

Learner approval closes the Bolt review step and records Gate E as approved.

## Copy-Paste Commands

From `cmsc-125-cpu-scheduling/` target path:

```powershell
Compress-Archive -Path california_fcfs.c,california_sjf.c,california_prio.c,california_rr.c,california_rfm.pdf -DestinationPath california.zip -Force
tar -tf california.zip
```

```powershell
Add-Type -AssemblyName System.IO.Compression.FileSystem
$zip = [System.IO.Compression.ZipFile]::OpenRead("california.zip")
$zip.Entries.Count
$zip.Entries | ForEach-Object FullName
$zip.Dispose()
```

## Pitfalls and Debugging Guidance

### 1) Accidental extra entries

Do not zip whole directories; use explicit filenames only.

### 2) Nested-path regression

If an entry contains `/` or `\`, rebuild the archive from file-level paths.

### 3) Tooling mismatch

If `unzip` is unavailable, use `tar -tf` and `.NET ZipFile` to maintain equivalent evidence.

## Practice Task

Run `deploy.task` using:

- `DEPLOY_SOURCE: cmsc-125-cpu-scheduling/REQUIREMENTS.md`
- `DEPLOY_TARGET: cmsc-125-cpu-scheduling/`

Then run `ops.task` after deployment readiness outputs are validated.

## Self-Check

You are aligned with `0.0.9` if:

- `REQUIREMENTS.md` shows Bolt `B-G1` with all checklist items checked
- `T-G1` evidence confirms exactly five required entries in `california.zip`
- Gate E is marked learner-approved in requirements and traceability notes
- root docs (`README.md`, `CHANGELOG.md`, version docs) reflect Unit G completion

## Next Steps

1. Execute `deploy.task` to produce deployment-unit readiness and handoff artifacts.
2. Execute `ops.task` to capture retention/runbook/ops-signal evidence for post-submission traceability.
