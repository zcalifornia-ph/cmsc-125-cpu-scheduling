# Round Robin Scheduling

Round Robin (RR) scheduling is mainly designed for time-sharing systems. This algorithm is similar to FCFS scheduling, but in Round Robin scheduling, **preemption** is added, which enables the system to switch between processes.

A fixed time is allotted to each process, called a **quantum**, for execution.

- Once a process executes for the given time period, that process is preempted and another process executes for the next time period.
- Context switching is used to save the states of preempted processes.
- This algorithm is simple and easy to implement.
- It is starvation-free because all processes get a fair share of the CPU.
- The time quantum is generally from `10` to `100` milliseconds.

## Characteristics of the Round Robin Algorithm

Some important characteristics of the Round Robin (RR) algorithm are as follows:

- Round Robin resides under the category of preemptive algorithms.
- It is one of the oldest, easiest, and fairest algorithms.
- It is a real-time algorithm because it responds to events within a specific time limit.
- In this algorithm, the time slice should be the minimum assigned to a specific task that needs to be processed, though it may vary for different operating systems.
- It is a hybrid model and is clock-driven in nature.
- It is a widely used scheduling method in traditional operating systems.

## Important Terms Related to Round Robin Scheduling

### Completion Time

It is the time at which any process completes its execution.

### Turn Around Time

This indicates the time difference between completion time and arrival time.

**Formula:** `Turn Around Time = Completion Time - Arrival Time`

### Waiting Time (W.T.)

It indicates the time difference between turnaround time and burst time.

**Formula:** `Waiting Time = Turn Around Time - Burst Time`

## Round Robin Scheduling Implementation

Below is a C++ implementation of Round Robin scheduling.

```cpp
// Program implementation in C++ for Round Robin scheduling
#include<iostream>
using namespace std;

//The Function to find the waiting time for all processes
void fWaitingTime(int processes[], int n,
            int bt[], int wt[], int quantum)
{
    // Let us Make a copy of burst times bt[] to store remaining burst times

    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = bt[i];

    int t = 0; // for Current time

    // Let us keep traverse the processes in the round robin manner until all of them are not done.

    while (1)
    {
        bool done = true;

        //let us Traverse all processes one by one repeatedly
        for (int i = 0 ; i < n; i++)
        {
            // If burst time of a process is greater than 0 then there is a need to process further
            if (rem_bt[i] > 0)
            {
                done = false; // indicates there is a pending process

                if (rem_bt[i] > quantum)
                {
                    // By Increasing the value of t it shows how much time a process has been processed
                    t += quantum;

                    // Decreasing the burst_time of current process by the quantum
                    rem_bt[i] -= quantum;
                }

                // If burst time is smaller than or equal to the quantum then it is Last cycle for this process
                else
                {
                    // Increase the value of t to show how much time a process has been processed
                    t = t + rem_bt[i];

                    // Waiting time is current time minus time used by this process.
                    wt[i] = t - bt[i];

                    // As the process gets fully executed thus remaining burst time becomes 0.

                    rem_bt[i] = 0;
                }
            }
        }

        // If all the processes are done
        if (done == true)
        break;
    }
}

// Function used to calculate the turn around time
void fTurnAroundTime(int processes[], int n,
                        int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate the average time
void findavgTime(int processes[], int n, int bt[],
                                    int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    fWaitingTime(processes, n, bt, wt, quantum);

    // Function to find turn around time for all processes
    fTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    cout << "Processes "<< " Burst time "
        << " Waiting time " << " Turn around time\n";

    // Calculate the total waiting time and total turn
    // around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
            << wt[i] <<"\t\t " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
}

//Given below is the Driver Code
int main()
{
    // process id's
    int processes[] = { 1, 2, 3,4};
    int x = sizeof processes / sizeof processes[0];

    // Burst time of all processes
    int burst_time[] = {21, 13, 6,12};

    // Time quantum
    int quantum = 2;
    findavgTime(processes, x, burst_time, quantum);
    return 0;
}
```

## Output

The original source dump indicated that an output section should appear here, but no actual output text was included.

## Advantages of Round Robin Scheduling Algorithm

Some advantages of the Round Robin scheduling algorithm are as follows:

- a particular time quantum is allocated to different jobs
- in terms of average response time, this algorithm gives strong performance
- all jobs get a fair allocation of CPU
- there are no issues of starvation or convoy effect
- the algorithm deals with all processes without any priority
- the algorithm is cyclic in nature
- a newly created process is added to the end of the ready queue
- a Round Robin scheduler generally employs time-sharing, meaning each job gets a time slot or quantum
- each process gets a chance to be rescheduled after a particular quantum time

## Disadvantages of Round Robin Scheduling Algorithm

Some disadvantages of the Round Robin scheduling algorithm are as follows:

- it spends more time on context switches
- for a small quantum, it becomes time-consuming
- it offers larger waiting time and response time
- throughput is low
- if the time quantum is too small, the Gantt chart becomes very large

## Some Points to Remember

### 1. Decreasing Value of Time Quantum

With a decreasing value of time quantum:

- the number of context switches increases
- response time decreases
- chances of starvation decrease
- for a smaller time quantum, it becomes better in terms of response time

### 2. Increasing Value of Time Quantum

With an increasing value of time quantum:

- the number of context switches decreases
- response time increases
- chances of starvation increase
- for a higher time quantum, it becomes better in terms of the number of context switches

If the value of time quantum keeps increasing, then Round Robin scheduling tends to become FCFS scheduling.

When the value of time quantum tends to infinity, Round Robin scheduling becomes FCFS scheduling.

Thus, the performance of Round Robin scheduling mainly depends on the value of the time quantum, and that value should be neither too big nor too small.
