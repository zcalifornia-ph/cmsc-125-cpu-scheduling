/* Round Robin (quantum = 3) on shared dataset from ai-dlc-docs/design-artifacts/shared-dataset-spec.md */
#include <stdio.h>

#define PROCESS_COUNT 5
#define QUANTUM 3
#define EXEC_ORDER_SIZE 512

typedef struct {
    int pid;
    int bt;
    int wt;
    int rt;
    int tat;
    int remaining_bt;
    int first_dispatch;
} Process;

void simulate_rr(Process processes[], int count, char exec_order[], size_t exec_order_size);
void compute_response_times(Process processes[], int count);
void compute_turnaround_times(Process processes[], int count);
void compute_averages(const Process processes[], int count, double *avg_wt, double *avg_rt, double *avg_tat);
void print_table(const Process processes[], int count, const char exec_order[]);

void simulate_rr(Process processes[], int count, char exec_order[], size_t exec_order_size) {
    int exec_len = 0;
    int completed = 0;
    int t = 0;

    if (exec_order_size > 0) {
        exec_order[0] = '\0';
    }

    for (int i = 0; i < count; ++i) {
        processes[i].remaining_bt = processes[i].bt;
        processes[i].first_dispatch = -1;
        processes[i].wt = 0;
        processes[i].rt = 0;
        processes[i].tat = 0;
    }

    while (completed < count) {
        for (int i = 0; i < count; ++i) {
            if (processes[i].remaining_bt <= 0) {
                continue;
            }

            if (processes[i].first_dispatch == -1) {
                processes[i].first_dispatch = t;
            }

            if ((size_t)exec_len < exec_order_size) {
                int written = snprintf(exec_order + exec_len,
                                       exec_order_size - (size_t)exec_len,
                                       "%sP%d",
                                       exec_len ? ", " : "",
                                       processes[i].pid);
                if (written > 0) {
                    exec_len += written;
                    if ((size_t)exec_len >= exec_order_size) {
                        exec_len = (int)exec_order_size - 1;
                        exec_order[exec_len] = '\0';
                    }
                }
            }

            if (processes[i].remaining_bt > QUANTUM) {
                t += QUANTUM;
                processes[i].remaining_bt -= QUANTUM;
            } else {
                t += processes[i].remaining_bt;
                processes[i].wt = t - processes[i].bt;
                processes[i].remaining_bt = 0;
                completed++;
            }
        }
    }
}

void compute_response_times(Process processes[], int count) {
    for (int i = 0; i < count; ++i) {
        processes[i].rt = processes[i].first_dispatch;
    }
}

void compute_turnaround_times(Process processes[], int count) {
    for (int i = 0; i < count; ++i) {
        processes[i].tat = processes[i].wt + processes[i].bt;
    }
}

void compute_averages(const Process processes[], int count, double *avg_wt, double *avg_rt, double *avg_tat) {
    int sum_wt = 0;
    int sum_rt = 0;
    int sum_tat = 0;

    for (int i = 0; i < count; ++i) {
        sum_wt += processes[i].wt;
        sum_rt += processes[i].rt;
        sum_tat += processes[i].tat;
    }

    *avg_wt = (double)sum_wt / count;
    *avg_rt = (double)sum_rt / count;
    *avg_tat = (double)sum_tat / count;
}

void print_table(const Process processes[], int count, const char exec_order[]) {
    printf("Execution Order: %s\n", exec_order);
    printf("PID   BT   WT   RT   TAT\n");

    for (int i = 0; i < count; ++i) {
        printf("P%-4d%-5d%-5d%-5d%-5d\n",
               processes[i].pid,
               processes[i].bt,
               processes[i].wt,
               processes[i].rt,
               processes[i].tat);
    }
}

int main(void) {
    Process processes[PROCESS_COUNT] = {
        {1, 8, 0, 0, 0, 0, 0},
        {2, 4, 0, 0, 0, 0, 0},
        {3, 9, 0, 0, 0, 0, 0},
        {4, 5, 0, 0, 0, 0, 0},
        {5, 2, 0, 0, 0, 0, 0}
    };
    char exec_order[EXEC_ORDER_SIZE];
    double avg_wt;
    double avg_rt;
    double avg_tat;

    simulate_rr(processes, PROCESS_COUNT, exec_order, sizeof exec_order);
    compute_response_times(processes, PROCESS_COUNT);
    compute_turnaround_times(processes, PROCESS_COUNT);
    compute_averages(processes, PROCESS_COUNT, &avg_wt, &avg_rt, &avg_tat);
    print_table(processes, PROCESS_COUNT, exec_order);

    printf("Average WT: %.2f\n", avg_wt);
    printf("Average RT: %.2f\n", avg_rt);
    printf("Average TAT: %.2f\n", avg_tat);

    return 0;
}
