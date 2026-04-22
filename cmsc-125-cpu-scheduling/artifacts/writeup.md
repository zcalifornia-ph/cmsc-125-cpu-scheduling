# Comparative Scheduling Write-up (FCFS vs SJF vs RR)

This comparison is intentionally scoped to **FCFS, SJF, and RR only** (Priority excluded for `US-F2`).  
The averages below are taken from actual program outputs recorded in:
`ai-dlc-docs/test-artifacts/u-b/t-b1-evidence.md`,
`ai-dlc-docs/test-artifacts/u-c/t-c1-evidence.md`, and
`ai-dlc-docs/test-artifacts/u-d/t-d1-evidence.md`.

| Algorithm | AWT | ART | ATT |
|---|---:|---:|---:|
| FCFS | 13.40 | 13.40 | 19.00 |
| SJF | 7.60 | 7.60 | 13.20 |
| RR (q=3) | 16.00 | 6.00 | 21.60 |

For **average waiting time (AWT)**, SJF is best (`7.60`) because shortest-first ordering minimizes cumulative waiting across the queue. RR is highest (`16.00`) because time slicing rotates work and reintroduces waiting between slices. FCFS lands between (`13.40`) because it preserves fixed arrival order and does not reorder by burst length.

For **average response time (ART)**, RR is best (`6.00`) because round-robin dispatch caps time-to-first-slice at `(n-1)*q = 12` for this dataset, so every process gets CPU attention early. FCFS (`13.40`) and SJF (`7.60`) are non-preemptive and arrival is `0`, so ART tracks each process's initial wait before first dispatch.
FCFS and SJF show `ART == AWT` because arrival time is `0` for all processes and neither preempts, so first dispatch happens exactly when each process leaves the waiting state.

For **average turnaround time (ATT)**, SJF is best (`13.20`) because early completion of short jobs reduces total completion-time accumulation. RR is highest (`21.60`) due to repeated queue cycling before completion. FCFS lands between (`19.00`) from fixed arrival order, no preemption cost, but no burst-aware ordering.
Across all three metrics, SJF dominates for this dataset; RR trades worse `AWT`/`ATT` for the best `ART`, which is the right trade when interactivity matters.
