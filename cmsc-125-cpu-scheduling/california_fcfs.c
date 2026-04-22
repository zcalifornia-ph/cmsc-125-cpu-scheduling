/* FCFS scheduling on the shared dataset defined in ai-dlc-docs/design-artifacts/shared-dataset-spec.md. */
#include <stdio.h>

#define PROCESS_COUNT 5

void compute_waiting_times(const int bt[], int wt[], int n) {
    int i;
    wt[0] = 0;
    for (i = 1; i < n; ++i) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void compute_response_times(const int wt[], int rt[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        rt[i] = wt[i];
    }
}

void compute_turnaround_times(const int bt[], const int wt[], int tat[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        tat[i] = wt[i] + bt[i];
    }
}

void compute_averages(const int wt[], const int rt[], const int tat[], int n,
                      double *awt, double *art, double *att) {
    int i;
    int total_wt = 0;
    int total_rt = 0;
    int total_tat = 0;

    for (i = 0; i < n; ++i) {
        total_wt += wt[i];
        total_rt += rt[i];
        total_tat += tat[i];
    }

    *awt = (double)total_wt / n;
    *art = (double)total_rt / n;
    *att = (double)total_tat / n;
}

void print_table(const int pid[], const int bt[], const int wt[], const int rt[], const int tat[],
                 int n, double awt, double art, double att) {
    int i;

    printf("Execution order: P1, P2, P3, P4, P5\n");
    printf("PID   BT   WT   RT   TAT\n");
    for (i = 0; i < n; ++i) {
        printf("P%-4d%-5d%-5d%-5d%d\n", pid[i], bt[i], wt[i], rt[i], tat[i]);
    }
    printf("Average WT: %.2f\n", awt);
    printf("Average RT: %.2f\n", art);
    printf("Average TAT: %.2f\n", att);
}

int main(void) {
    int pid[PROCESS_COUNT] = {1, 2, 3, 4, 5};
    int bt[PROCESS_COUNT] = {8, 4, 9, 5, 2};
    int wt[PROCESS_COUNT];
    int rt[PROCESS_COUNT];
    int tat[PROCESS_COUNT];
    double awt;
    double art;
    double att;

    compute_waiting_times(bt, wt, PROCESS_COUNT);
    compute_response_times(wt, rt, PROCESS_COUNT);
    compute_turnaround_times(bt, wt, tat, PROCESS_COUNT);
    compute_averages(wt, rt, tat, PROCESS_COUNT, &awt, &art, &att);
    print_table(pid, bt, wt, rt, tat, PROCESS_COUNT, awt, art, att);

    return 0;
}
