/* Non-preemptive Priority scheduling: higher priority number = higher priority */
#include <stdio.h>

#define PROCESS_COUNT 5

typedef struct {
    int pid;
    int bt;
    int prio;
    int wt;
    int rt;
    int tat;
} Process;

static void sort_by_priority(Process processes[], int count) {
    int i;
    for (i = 1; i < count; ++i) {
        Process key = processes[i];
        int j = i - 1;

        /* Stable tie-break by PID for deterministic output. */
        while (j >= 0 &&
               (processes[j].prio < key.prio ||
                (processes[j].prio == key.prio && processes[j].pid > key.pid))) {
            processes[j + 1] = processes[j];
            --j;
        }
        processes[j + 1] = key;
    }
}

static void compute_waiting_times(Process processes[], int count) {
    int i;
    processes[0].wt = 0;
    for (i = 1; i < count; ++i) {
        processes[i].wt = processes[i - 1].wt + processes[i - 1].bt;
    }
}

static void compute_response_times(Process processes[], int count) {
    int i;
    for (i = 0; i < count; ++i) {
        processes[i].rt = processes[i].wt;
    }
}

static void compute_turnaround_times(Process processes[], int count) {
    int i;
    for (i = 0; i < count; ++i) {
        processes[i].tat = processes[i].wt + processes[i].bt;
    }
}

static void compute_averages(const Process processes[], int count,
                             double *avg_wt, double *avg_rt, double *avg_tat) {
    int i;
    int total_wt = 0;
    int total_rt = 0;
    int total_tat = 0;

    for (i = 0; i < count; ++i) {
        total_wt += processes[i].wt;
        total_rt += processes[i].rt;
        total_tat += processes[i].tat;
    }

    *avg_wt = (double)total_wt / count;
    *avg_rt = (double)total_rt / count;
    *avg_tat = (double)total_tat / count;
}

static void print_execution_order(const Process processes[], int count) {
    int i;
    printf("Execution Order: ");
    for (i = 0; i < count; ++i) {
        printf("P%d", processes[i].pid);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

static void print_table(const Process processes[], int count,
                        double avg_wt, double avg_rt, double avg_tat) {
    int i;

    printf("PID   BT   PRIO   WT   RT   TAT\n");
    for (i = 0; i < count; ++i) {
        printf("P%-4d%-5d%-7d%-5d%-5d%d\n",
               processes[i].pid,
               processes[i].bt,
               processes[i].prio,
               processes[i].wt,
               processes[i].rt,
               processes[i].tat);
    }

    printf("Average WT: %.2f\n", avg_wt);
    printf("Average RT: %.2f\n", avg_rt);
    printf("Average TAT: %.2f\n", avg_tat);
}

int main(void) {
    Process processes[PROCESS_COUNT] = {
        {1, 8, 3, 0, 0, 0},
        {2, 4, 1, 0, 0, 0},
        {3, 9, 4, 0, 0, 0},
        {4, 5, 2, 0, 0, 0},
        {5, 2, 5, 0, 0, 0}
    };
    double avg_wt;
    double avg_rt;
    double avg_tat;

    sort_by_priority(processes, PROCESS_COUNT);
    compute_waiting_times(processes, PROCESS_COUNT);
    compute_response_times(processes, PROCESS_COUNT);
    compute_turnaround_times(processes, PROCESS_COUNT);
    compute_averages(processes, PROCESS_COUNT, &avg_wt, &avg_rt, &avg_tat);

    print_execution_order(processes, PROCESS_COUNT);
    print_table(processes, PROCESS_COUNT, avg_wt, avg_rt, avg_tat);

    return 0;
}
