/*
 * Non-preemptive Shortest Job First (SJF) scheduling.
 * Shared dataset source: ai-dlc-docs/design-artifacts/shared-dataset-spec.md
 */
#include <stdio.h>

#define PROCESS_COUNT 5

typedef struct {
    int pid;
    int bt;
    int wt;
    int rt;
    int tat;
} Process;

static void sort_by_burst_time(Process processes[], int count) {
    int i;
    for (i = 1; i < count; i++) {
        Process key = processes[i];
        int j = i - 1;

        /* Stable tie-break by PID for deterministic output. */
        while (j >= 0 &&
               (processes[j].bt > key.bt ||
                (processes[j].bt == key.bt && processes[j].pid > key.pid))) {
            processes[j + 1] = processes[j];
            j--;
        }

        processes[j + 1] = key;
    }
}

static void compute_waiting_times(Process processes[], int count) {
    int i;
    processes[0].wt = 0;

    for (i = 1; i < count; i++) {
        processes[i].wt = processes[i - 1].wt + processes[i - 1].bt;
    }
}

static void compute_response_times(Process processes[], int count) {
    int i;
    for (i = 0; i < count; i++) {
        processes[i].rt = processes[i].wt;
    }
}

static void compute_turnaround_times(Process processes[], int count) {
    int i;
    for (i = 0; i < count; i++) {
        processes[i].tat = processes[i].wt + processes[i].bt;
    }
}

static void compute_averages(const Process processes[], int count,
                             double *avg_wt, double *avg_rt, double *avg_tat) {
    int i;
    int total_wt = 0;
    int total_rt = 0;
    int total_tat = 0;

    for (i = 0; i < count; i++) {
        total_wt += processes[i].wt;
        total_rt += processes[i].rt;
        total_tat += processes[i].tat;
    }

    *avg_wt = (double)total_wt / count;
    *avg_rt = (double)total_rt / count;
    *avg_tat = (double)total_tat / count;
}

static void print_table(const Process processes[], int count,
                        double avg_wt, double avg_rt, double avg_tat) {
    int i;

    printf("Execution Order: ");
    for (i = 0; i < count; i++) {
        printf("P%d", processes[i].pid);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf("\n\n");

    printf("%-5s %-5s %-5s %-5s %-5s\n", "PID", "BT", "WT", "RT", "TAT");
    for (i = 0; i < count; i++) {
        printf("%-5d %-5d %-5d %-5d %-5d\n",
               processes[i].pid,
               processes[i].bt,
               processes[i].wt,
               processes[i].rt,
               processes[i].tat);
    }

    printf("\nAverage WT: %.2f\n", avg_wt);
    printf("Average RT: %.2f\n", avg_rt);
    printf("Average TAT: %.2f\n", avg_tat);
}

int main(void) {
    Process processes[PROCESS_COUNT] = {
        {1, 8, 0, 0, 0},
        {2, 4, 0, 0, 0},
        {3, 9, 0, 0, 0},
        {4, 5, 0, 0, 0},
        {5, 2, 0, 0, 0}
    };
    double avg_wt;
    double avg_rt;
    double avg_tat;

    sort_by_burst_time(processes, PROCESS_COUNT);
    compute_waiting_times(processes, PROCESS_COUNT);
    compute_response_times(processes, PROCESS_COUNT);
    compute_turnaround_times(processes, PROCESS_COUNT);
    compute_averages(processes, PROCESS_COUNT, &avg_wt, &avg_rt, &avg_tat);
    print_table(processes, PROCESS_COUNT, avg_wt, avg_rt, avg_tat);

    return 0;
}
