/* Non-preemptive Priority scheduling: higher priority number = higher priority */
#include <stdio.h>

#define N 4

typedef struct {
    int pid;
    int bt;
    int prio;
} Process;

static void sort_by_priority(Process processes[], int n) {
    int i;
    for (i = 1; i < n; ++i) {
        Process key = processes[i];
        int j = i - 1;

        while (j >= 0 &&
               (processes[j].prio < key.prio ||
                (processes[j].prio == key.prio && processes[j].pid > key.pid))) {
            processes[j + 1] = processes[j];
            --j;
        }
        processes[j + 1] = key;
    }
}

static void compute_waiting_times(const Process processes[], int wt[], int n) {
    int i;
    wt[0] = 0;
    for (i = 1; i < n; ++i) {
        wt[i] = wt[i - 1] + processes[i - 1].bt;
    }
}

static void compute_response_times(const int wt[], int rt[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        rt[i] = wt[i];
    }
}

static void compute_turnaround_times(const Process processes[], const int wt[], int tat[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        tat[i] = wt[i] + processes[i].bt;
    }
}

static void compute_averages(const int wt[], const int rt[], const int tat[], int n,
                             double *avg_wt, double *avg_rt, double *avg_tat) {
    int i;
    int total_wt = 0;
    int total_rt = 0;
    int total_tat = 0;

    for (i = 0; i < n; ++i) {
        total_wt += wt[i];
        total_rt += rt[i];
        total_tat += tat[i];
    }

    *avg_wt = (double)total_wt / n;
    *avg_rt = (double)total_rt / n;
    *avg_tat = (double)total_tat / n;
}

static void print_execution_order(const Process processes[], int n) {
    int i;
    printf("Execution Order: ");
    for (i = 0; i < n; ++i) {
        printf("P%d", processes[i].pid);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

static void print_table(const Process processes[], const int wt[], const int rt[], const int tat[], int n,
                        double avg_wt, double avg_rt, double avg_tat) {
    int i;

    printf("PID   BT   PRIO   WT   RT   TAT\n");
    for (i = 0; i < n; ++i) {
        printf("P%-4d%-5d%-7d%-5d%-5d%d\n",
               processes[i].pid, processes[i].bt, processes[i].prio, wt[i], rt[i], tat[i]);
    }

    printf("Average WT: %.2f\n", avg_wt);
    printf("Average RT: %.2f\n", avg_rt);
    printf("Average TAT: %.2f\n", avg_tat);
}

int main(void) {
    Process processes[N] = {
        {1, 10, 3},
        {2, 6, 1},
        {3, 4, 4},
        {4, 8, 2}
    };
    int wt[N];
    int rt[N];
    int tat[N];
    double avg_wt;
    double avg_rt;
    double avg_tat;

    sort_by_priority(processes, N);
    compute_waiting_times(processes, wt, N);
    compute_response_times(wt, rt, N);
    compute_turnaround_times(processes, wt, tat, N);
    compute_averages(wt, rt, tat, N, &avg_wt, &avg_rt, &avg_tat);

    print_execution_order(processes, N);
    print_table(processes, wt, rt, tat, N, avg_wt, avg_rt, avg_tat);

    return 0;
}
