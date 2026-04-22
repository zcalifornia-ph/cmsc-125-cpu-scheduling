/* Round Robin (quantum = 3) on shared dataset from ai-dlc-docs/design-artifacts/shared-dataset-spec.md */
#include <stdio.h>

#define PROCESS_COUNT 5
#define QUANTUM 3
#define EXEC_ORDER_SIZE 512

void simulate_rr(const int pid[], const int bt[], int wt[], int first_dispatch[],
                 char exec_order[], size_t exec_order_size);
void compute_response_times(const int first_dispatch[], int rt[]);
void compute_turnaround_times(const int bt[], const int wt[], int tat[]);
void compute_averages(const int wt[], const int rt[], const int tat[], double *avg_wt, double *avg_rt, double *avg_tat);
void print_table(const int pid[], const int bt[], const int wt[], const int rt[], const int tat[],
                 const char exec_order[]);

void simulate_rr(const int pid[], const int bt[], int wt[], int first_dispatch[],
                 char exec_order[], size_t exec_order_size) {
    int remaining[PROCESS_COUNT];
    int exec_len = 0;
    int completed = 0;
    int t = 0;

    if (exec_order_size > 0) {
        exec_order[0] = '\0';
    }

    for (int i = 0; i < PROCESS_COUNT; ++i) {
        remaining[i] = bt[i];
        first_dispatch[i] = -1;
        wt[i] = 0;
    }

    while (completed < PROCESS_COUNT) {
        for (int i = 0; i < PROCESS_COUNT; ++i) {
            if (remaining[i] <= 0) {
                continue;
            }

            if (first_dispatch[i] == -1) {
                first_dispatch[i] = t;
            }

            if ((size_t)exec_len < exec_order_size) {
                int written = snprintf(exec_order + exec_len,
                                       exec_order_size - (size_t)exec_len,
                                       "%sP%d",
                                       exec_len ? ", " : "",
                                       pid[i]);
                if (written > 0) {
                    exec_len += written;
                    if ((size_t)exec_len >= exec_order_size) {
                        exec_len = (int)exec_order_size - 1;
                        exec_order[exec_len] = '\0';
                    }
                }
            }

            if (remaining[i] > QUANTUM) {
                t += QUANTUM;
                remaining[i] -= QUANTUM;
            } else {
                t += remaining[i];
                wt[i] = t - bt[i];
                remaining[i] = 0;
                completed++;
            }
        }
    }
}

void compute_response_times(const int first_dispatch[], int rt[]) {
    for (int i = 0; i < PROCESS_COUNT; ++i) {
        rt[i] = first_dispatch[i];
    }
}

void compute_turnaround_times(const int bt[], const int wt[], int tat[]) {
    for (int i = 0; i < PROCESS_COUNT; ++i) {
        tat[i] = wt[i] + bt[i];
    }
}

void compute_averages(const int wt[], const int rt[], const int tat[], double *avg_wt, double *avg_rt, double *avg_tat) {
    int sum_wt = 0;
    int sum_rt = 0;
    int sum_tat = 0;

    for (int i = 0; i < PROCESS_COUNT; ++i) {
        sum_wt += wt[i];
        sum_rt += rt[i];
        sum_tat += tat[i];
    }

    *avg_wt = (double)sum_wt / PROCESS_COUNT;
    *avg_rt = (double)sum_rt / PROCESS_COUNT;
    *avg_tat = (double)sum_tat / PROCESS_COUNT;
}

void print_table(const int pid[], const int bt[], const int wt[], const int rt[], const int tat[],
                 const char exec_order[]) {
    printf("Execution Order: %s\n", exec_order);
    printf("PID   BT   WT   RT   TAT\n");

    for (int i = 0; i < PROCESS_COUNT; ++i) {
        printf("P%-4d%-5d%-5d%-5d%-5d\n", pid[i], bt[i], wt[i], rt[i], tat[i]);
    }
}

int main(void) {
    int pid[PROCESS_COUNT] = {1, 2, 3, 4, 5};
    int bt[PROCESS_COUNT] = {8, 4, 9, 5, 2};
    int wt[PROCESS_COUNT];
    int first_dispatch[PROCESS_COUNT];
    int rt[PROCESS_COUNT];
    int tat[PROCESS_COUNT];
    char exec_order[EXEC_ORDER_SIZE];
    double avg_wt;
    double avg_rt;
    double avg_tat;

    simulate_rr(pid, bt, wt, first_dispatch, exec_order, sizeof exec_order);
    compute_response_times(first_dispatch, rt);
    compute_turnaround_times(bt, wt, tat);
    compute_averages(wt, rt, tat, &avg_wt, &avg_rt, &avg_tat);
    print_table(pid, bt, wt, rt, tat, exec_order);

    printf("Average WT: %.2f\n", avg_wt);
    printf("Average RT: %.2f\n", avg_rt);
    printf("Average TAT: %.2f\n", avg_tat);

    return 0;
}
