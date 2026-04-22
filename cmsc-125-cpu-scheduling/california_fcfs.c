/* FCFS scheduling on the shared dataset defined in ai-dlc-docs/design-artifacts/shared-dataset-spec.md. */
#include <stdio.h>

#define PROCESS_COUNT 5

typedef struct {
    int pid;
    int bt;
    int wt;
    int rt;
    int tat;
} Process;

void compute_waiting_times(Process processes[], int n) {
    int i;
    processes[0].wt = 0;
    for (i = 1; i < n; ++i) {
        processes[i].wt = processes[i - 1].wt + processes[i - 1].bt;
    }
}

void compute_response_times(Process processes[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        processes[i].rt = processes[i].wt;
    }
}

void compute_turnaround_times(Process processes[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        processes[i].tat = processes[i].wt + processes[i].bt;
    }
}

void compute_averages(const Process processes[], int n,
                      double *awt, double *art, double *att) {
    int i;
    int total_wt = 0;
    int total_rt = 0;
    int total_tat = 0;

    for (i = 0; i < n; ++i) {
        total_wt += processes[i].wt;
        total_rt += processes[i].rt;
        total_tat += processes[i].tat;
    }

    *awt = (double)total_wt / n;
    *art = (double)total_rt / n;
    *att = (double)total_tat / n;
}

void print_table(const Process processes[], int n, double awt, double art, double att) {
    int i;

    printf("Execution Order: ");
    for (i = 0; i < n; ++i) {
        printf("P%d", processes[i].pid);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");

    printf("PID   BT   WT   RT   TAT\n");
    for (i = 0; i < n; ++i) {
        printf("P%-4d%-5d%-5d%-5d%d\n",
               processes[i].pid,
               processes[i].bt,
               processes[i].wt,
               processes[i].rt,
               processes[i].tat);
    }
    printf("Average WT: %.2f\n", awt);
    printf("Average RT: %.2f\n", art);
    printf("Average TAT: %.2f\n", att);
}

int main(void) {
    Process processes[PROCESS_COUNT] = {
        {1, 8, 0, 0, 0},
        {2, 4, 0, 0, 0},
        {3, 9, 0, 0, 0},
        {4, 5, 0, 0, 0},
        {5, 2, 0, 0, 0}
    };
    double awt;
    double art;
    double att;

    compute_waiting_times(processes, PROCESS_COUNT);
    compute_response_times(processes, PROCESS_COUNT);
    compute_turnaround_times(processes, PROCESS_COUNT);
    compute_averages(processes, PROCESS_COUNT, &awt, &art, &att);
    print_table(processes, PROCESS_COUNT, awt, art, att);

    return 0;
}
