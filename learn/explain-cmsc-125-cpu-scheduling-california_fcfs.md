# california_fcfs.c Explained (FCFS CPU Scheduling)

## 1. Title
`cmsc-125-cpu-scheduling/california_fcfs.c` - First-Come, First-Served scheduling with fixed shared dataset.

## 2. Quick Diagnostic Read
Prerequisites:
- Basic C arrays, loops, and function parameters.
- CPU scheduling terms: `WT` (waiting time), `RT` (response time), `TAT` (turnaround time).

High-value in this file:
- It shows the full FCFS metric pipeline in small, testable helper functions.
- It uses the dataset frozen by the shared dataset spec, so outputs are directly comparable with SJF and RR implementations.

## 3. One-Sentence Objective
Understand exactly how this C file computes and prints FCFS `WT`, `RT`, `TAT`, plus averages, for five hardcoded processes.

## 4. Why This File Matters
This file is the FCFS baseline implementation in the repo's scheduling comparison set. If this baseline is wrong, later algorithm comparisons are misleading. Because the data is fixed across algorithms, correctness here is foundational for apples-to-apples evaluation.

## 5. Plan A / Plan B
Plan A (code-first, 25-35 minutes):
- Read the helper functions in order (`compute_waiting_times` -> `compute_response_times` -> `compute_turnaround_times` -> `compute_averages`).
- Manually compute one row (for `P3`) and verify with printed output.

Plan B (concept-first, 20-30 minutes):
- Start from formulas (`WT`, `RT`, `TAT`, averages).
- Then map each formula to the function that implements it.

## 6. System View / Mental Model
```text
Fixed dataset (PID, BT)
   -> compute_waiting_times()
   -> compute_response_times()
   -> compute_turnaround_times()
   -> compute_averages()
   -> print_table()
```

Mental model: this is a linear data-processing pipeline. Each stage adds one derived metric array, then the final stage prints everything.

## 7. What This File Is and Where It Fits
- File type: C source file.
- Role: standalone FCFS metric calculator/formatter.
- Direct dependency: C standard I/O (`stdio.h`).
- Uses shared project contract: hardcoded shared dataset from `shared-dataset-spec.md`.
- Likely consumers: course/demo execution and cross-algorithm metric comparison.

## 8. Just-Enough Primer
- `const int bt[]` means the function promises not to modify `bt`.
- Arrays are passed as pointers; `n` controls valid index range.
- Output-by-pointer (`double *awt`) is used to return multiple averages.
- FCFS with all arrival times `0` implies `RT == WT` (observed in dataset spec, then implemented by copying `wt` into `rt`).

## 9. Whole-File Outline Mapped to Code Regions
- Lines 1-4: Header comment, include, and process count constant.
- Lines 6-12: `compute_waiting_times`.
- Lines 14-19: `compute_response_times`.
- Lines 21-26: `compute_turnaround_times`.
- Lines 28-44: `compute_averages`.
- Lines 46-58: `print_table`.
- Lines 60-77: `main` (dataset setup + orchestration).

## 10. Walkthrough by Section
Lines 1-4 (`#include`, `PROCESS_COUNT`):
- What: imports `printf` support and fixes process count to 5.
- Why: supports deterministic output shape.
- Inference: hardcoding `5` is chosen to match shared dataset comparability rules.
- Risk if changed carelessly: array sizes and print assumptions can desynchronize.

Lines 6-12 (`compute_waiting_times`):
- What: computes FCFS waiting times cumulatively.
- How: `wt[0]=0`; each next wait is previous wait plus previous burst (`wt[i]=wt[i-1]+bt[i-1]`).
- Data flow: input `bt[]`, output `wt[]`.
- Invariant: for valid `n>0`, `wt` is non-decreasing if bursts are non-negative.
- Break risk: an off-by-one here corrupts every downstream metric.

Lines 14-19 (`compute_response_times`):
- What: sets `rt[i] = wt[i]` for each process.
- Why: for this scenario (arrival time 0, non-preemptive FCFS), response time equals waiting time.
- Data flow: input `wt[]`, output `rt[]`.
- Side effects: writes entire `rt[]`.
- Break risk: replacing this with unrelated logic would violate metric definitions for this dataset.

Lines 21-26 (`compute_turnaround_times`):
- What: computes `tat[i] = wt[i] + bt[i]`.
- Why: equivalent to completion minus arrival when arrival is 0.
- Data flow: inputs `bt[]`, `wt[]`; output `tat[]`.
- Invariant: `tat[i] >= bt[i]` when `wt[i] >= 0`.
- Break risk: wrong `tat` invalidates both table and average turnaround.

Lines 28-44 (`compute_averages`):
- What: totals each metric array and divides by `n`.
- How: integer accumulation (`total_*`) then cast to double in final division.
- Data flow: inputs `wt[]`, `rt[]`, `tat[]`; outputs via pointers `awt`, `art`, `att`.
- Side effects: writes through three output pointers.
- Contract: `n` must be > 0 (no guard exists for divide-by-zero).

Lines 46-58 (`print_table`):
- What: prints execution order, per-process metrics, and averages.
- How: formatted table rows (`P%-4d%-5d%-5d%-5d%d`).
- Inference: output is tuned for fixed small integer widths.
- Break risk: formatting changes can make comparisons harder in manual review.

Lines 60-77 (`main`):
- What: defines shared dataset arrays and runs the pipeline in dependency order.
- Observed constants:
  - `pid = {1,2,3,4,5}`
  - `bt  = {8,4,9,5,2}`
- Why order matters: each later computation depends on earlier arrays (`wt` before `rt`/`tat`, all before averages).
- Side effects: console output only.

## 11. Data Flow / Control Flow / Dependency Map
Control flow:
1. `main` initializes arrays.
2. `compute_waiting_times` derives `wt`.
3. `compute_response_times` derives `rt` from `wt`.
4. `compute_turnaround_times` derives `tat` from `wt` and `bt`.
5. `compute_averages` derives scalars from arrays.
6. `print_table` emits results.

Dependency map:
- Internal: every helper is called only by `main`.
- External: `stdio.h` for output.
- Project-level supporting contract: shared dataset spec binds expected constants/formulas.

Safe modification points:
- Table labels/formatting (low runtime risk).
- Extracting repeated loops into reusable utility with tests.

Dangerous modification points:
- Waiting-time recurrence logic.
- Function call order in `main`.
- `n` handling in averages (currently assumes `n>0`).

## 12. Minimal Usage Example or Execution Trace
Hypothetical static trace (from actual code formulas and constants):
- `wt`: `[0, 8, 12, 21, 26]`
- `rt`: `[0, 8, 12, 21, 26]`
- `tat`: `[8, 12, 21, 26, 28]`
- Averages:
  - `AWT = (0+8+12+21+26)/5 = 13.40`
  - `ART = 13.40`
  - `ATT = (8+12+21+26+28)/5 = 19.00`

These values align with the shared dataset arithmetic cross-check.

## 13. Common Pitfalls / Misconceptions
- Thinking `RT` always equals `WT`: true here, not universally true for all scheduling contexts.
- Assuming this handles arbitrary arrivals: it does not; arrival times are not modeled in code.
- Missing `n > 0` precondition in `compute_averages`.
- Changing `PROCESS_COUNT` without updating dataset arrays.

## 14. Safe-Change Guide
Safer changes:
- Add input validation in `compute_averages` for `n <= 0`.
- Improve print alignment with wider formatting.
- Add comments documenting assumptions (`arrival=0`, non-preemptive FCFS).

Higher-risk changes:
- Altering recurrence equations.
- Reordering pipeline calls.
- Introducing dynamic process counts without reworking all array contracts.

## 15. Invariants / Contracts / Side Effects
Invariants:
- `PROCESS_COUNT` matches allocated array lengths in `main`.
- For this dataset, `rt[i] == wt[i]`.
- `tat[i] == wt[i] + bt[i]`.
- `n` consistently passed as the number of valid elements.

Contracts:
- Each compute function expects writable output arrays sized for `n` elements.
- `compute_averages` expects valid output pointers and `n > 0`.

Side effects:
- Metric functions mutate output arrays/pointers.
- `print_table` writes to stdout.

## 16. Self-Check or Practice Drill
Exercise (20-40 min):
- Modify only `bt` to `{3, 6, 1, 7, 4}` while keeping PID and count.
- Predict `WT`, `RT`, `TAT`, and averages by hand.
- Run and compare prediction with printed output.

Self-check rubric:
- Correct recurrence for all `wt` entries.
- Correct equality reasoning for `rt` in this setup.
- Correct `tat` formula application.
- Average calculations match to two decimals.

## 17. Artifact Map
Files read for this explanation:
- `cmsc-125-cpu-scheduling/california_fcfs.c` (target file; source of implementation facts).
- Project-level shared-dataset specification notes (supporting context for fixed dataset/formula validation).
- Internal explanation-task contract and study-guide template references (used for section structure and verification checklist).

## 18. Copy-Paste Prompt Examples
```text
explain.task cmsc-125-cpu-scheduling/california_fcfs.c
explain.task cmsc-125-cpu-scheduling/california_sjf.c
explain.task cmsc-125-cpu-scheduling/california_rr.c
explain.task docs/articles/first-come-first-serve.md
```

## 19. 24-72 Hour Next Steps
1. Explain one sibling scheduler (`california_sjf.c`) and compare which formulas stayed invariant vs changed.
2. Add a tiny test harness (or script) that verifies FCFS expected arrays for this dataset.
3. Refactor to support arrival times, then document exactly why `RT == WT` no longer always holds.
