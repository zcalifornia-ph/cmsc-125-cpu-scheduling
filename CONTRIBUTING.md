# Contributing

This repository primarily serves as an individual CMSC 125 assignment project.
External contributions are not the main workflow, but if changes are proposed, they should follow the standards below.

## Before Contributing

- Read `README.md` to understand the assignment scope and expected deliverables.
- Check whether the proposed change helps the CPU scheduling assignment directly.
- Open an issue first for substantial changes to scope, structure, or methodology.

## Contribution Standards

- Keep changes focused and easy to review.
- Preserve correctness of the scheduling logic and reported metrics.
- Do not replace required evidence with placeholders or unverifiable output.
- Update documentation when repository behavior, structure, or deliverables change.

## Coding Expectations

- Keep one source file per scheduling algorithm.
- Follow the assignment naming convention: `<surname>_<codename>.c` or `<surname>_<codename>.cpp`.
- Use the same dataset for FCFS, SJF, and RR unless the assignment instructions explicitly allow otherwise.
- Keep priority values explicit in the Priority Scheduling implementation.
- Prefer readable, well-structured code over clever but opaque shortcuts.

## Verification Expectations

Any contribution that changes scheduling behavior should include:

- the dataset used for validation
- the resulting output or screenshots
- a short explanation of how waiting, response, and turnaround metrics were checked

## Documentation Expectations

If you change filenames, algorithms, instructions, or deliverable structure, update the relevant root docs in the same change:

- `README.md`
- `CHANGELOG.md`
- `SECURITY.md`
- `CODE_OF_CONDUCT.md` when policy expectations change

## Pull Request Guidance

If pull requests are used, include:

- a short problem statement
- what changed
- how it was tested
- any risks, assumptions, or academic-integrity concerns

## Academic Integrity

This is an academic repository.
Do not submit plagiarized code, fabricated experimental results, or misleading documentation.
If reference implementations or external material influenced a change, say so clearly.

## Security Reporting

Do not disclose vulnerabilities through public issues first.
Use the process described in `SECURITY.md`.
