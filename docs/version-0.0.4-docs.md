# Version 0.0.4 Documentation

## Title

Reference article Markdown formatting and notice alignment for the CMSC 125 CPU Scheduling repository.

## Quick Diagnostic Read

This version does not add CPU scheduling implementations.
It improves the quality and readability of the repository's local study material.

What changed in `0.0.4`:

- five reference article files under `docs/articles/` were reformatted from raw text dumps into actual Markdown
- the root `README.md` now reflects the presence of those local formatted articles
- `THIRD-PARTY-NOTICES.md` now explicitly covers the `docs/articles/` material

What did not change:

- the repository license in `LICENSE.txt`
- the actual algorithm implementation status
- the assignment deliverable expectations

## One-Sentence Objective

Turn the local reference-article files into readable Markdown while keeping the repository-level versioning and ownership-boundary documentation accurate.

## Why This Version Matters

Before this update, the files in `docs/articles/` were difficult to read because they were effectively text dumps inside `.md` files.

That created three practical problems:

- the repository contained study material that did not render cleanly
- code samples and outputs were harder to scan
- the landing-page and notice docs did not explicitly reflect the new article set

Version `0.0.4` fixes the formatting problem and keeps the surrounding documentation consistent.

## Plan A / Plan B

### Plan A

Keep the article wording substantially intact, but convert the raw dumps into structured Markdown:

- one top-level heading per file
- real sections and subsections
- proper bullet or numbered lists
- fenced code blocks for C/C++ samples
- fenced text blocks for sample output when the source included output

This is the correct approach when readability is the goal and the content should remain materially the same.

### Plan B

Rewrite the articles heavily or silently invent missing examples.

That would be the wrong approach here because it would blur the line between formatting cleanup and content authoring.

For this repository, Plan A is the only defensible option.

## System View

After `0.0.4`, the documentation structure is clearer:

- `README.md` remains the landing page
- `CHANGELOG.md` records the version summary
- `docs/version-0.0.4-docs.md` explains this documentation pass in detail
- `docs/articles/` now acts as a readable local reference shelf
- `THIRD-PARTY-NOTICES.md` explicitly documents the ownership boundary for those reference articles

## Artifact Map

Files added or updated for this version:

- `README.md`
- `CHANGELOG.md`
- `THIRD-PARTY-NOTICES.md`
- `docs/version-0.0.4-docs.md`
- `docs/articles/cpu-scheduling.md`
- `docs/articles/first-come-first-serve.md`
- `docs/articles/priority-scheduling.md`
- `docs/articles/round-robin.md`
- `docs/articles/shortest-job-first.md`

## Guided Walkthrough

## 1) Article Structure Cleanup

Each article was normalized so it behaves like a real Markdown document instead of a pasted text block.

That included:

- removing duplicated top titles
- turning raw labels into section headings
- converting loose enumerations into proper lists
- separating embedded code into fenced `cpp` blocks
- separating inline output into fenced `text` blocks where output text actually existed

## 2) Content Preservation Discipline

The goal was formatting, not silent rewriting.

So the cleanup was intentionally conservative:

- the original instructional content was preserved as much as possible
- obvious scrape noise such as duplicated headings and share-widget text was removed
- missing data was not invented

One important example is `docs/articles/round-robin.md`: the original dump referenced an output section but did not actually include the output, so the formatted version keeps that gap explicit rather than fabricating result text.

## 3) README Synchronization

The root `README.md` was updated so it no longer behaves as if only the version docs exist under `docs/`.

The README now:

- updates the visible repository version to `0.0.4`
- points the latest-version link to `docs/version-0.0.4-docs.md`
- shows `docs/articles/` in the repository layout
- lists the local formatted reference articles in the reference-materials section

That keeps the landing page aligned with the actual repository contents.

## 4) Notice Boundary Alignment

Because `docs/articles/` contains reference material that is not the repository's original authored project content, `THIRD-PARTY-NOTICES.md` needed a precise update.

The file now makes two things explicit:

- `docs/articles/` is treated as third-party reference material
- local formatting for readability does not change the ownership boundary

That reduces ambiguity about what is repository-owned under MIT and what remains reference material.

## Copy-Paste Commands

Review the full documentation change:

```powershell
git diff -- README.md CHANGELOG.md THIRD-PARTY-NOTICES.md docs/version-0.0.4-docs.md docs/articles/
```

Stage the commit-task artifacts plus the formatted articles:

```powershell
git add README.md CHANGELOG.md THIRD-PARTY-NOTICES.md docs/version-0.0.4-docs.md docs/articles/
```

Confirm the staged result:

```powershell
git diff --cached
```

## Pitfalls and Debugging Guidance

### 1) Untracked files can hide the real change set

Because `docs/articles/` was untracked, relying only on `git diff` would not have described the work clearly.

When commit preparation follows earlier chat context, use that task context to understand the change set and then make the docs reflect it accurately.

### 2) Formatting cleanup can drift into content rewrite

When cleaning article dumps, avoid casually rewriting technical claims or inventing examples that were not present in the source material.

### 3) Notice files can fall behind content reality

If a repository adds local copies or formatted versions of third-party reference material, the notice boundary should be updated in the same change.

## Practice Task

If another reference article is added under `docs/articles/`, repeat this same pattern:

- format it as real Markdown
- cite or preserve the source reference when available
- update `THIRD-PARTY-NOTICES.md` if the new material changes the notice boundary
- add a new changelog/docs entry if the repository version changes

## Self-Check

You are done with `0.0.4` if:

- the five article files render as readable Markdown
- the README reflects the presence of `docs/articles/`
- the version marker and latest-version link point to `0.0.4`
- the third-party notice file explicitly covers the article directory

## Next Steps

1. Stage the formatted article files along with the root documentation updates.
2. Continue with the actual CPU scheduling source implementations.
3. After the first implementation milestone lands, update the README and changelog again so the repository status reflects code progress rather than only documentation progress.
