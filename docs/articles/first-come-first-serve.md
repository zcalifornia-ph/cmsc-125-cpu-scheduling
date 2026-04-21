# First Come First Serve Scheduling

In the **First Come First Serve (FCFS)** scheduling algorithm, as the name suggests, the process which arrives first gets executed first. In other words, the process which requests the CPU first gets the CPU allocated first.

First Come First Serve is just like the **FIFO (First In, First Out)** queue data structure, where the data element added to the queue first is the one that leaves the queue first.

- This is used in batch systems.
- It is easy to understand and implement programmatically using a queue data structure, where a new process enters through the tail of the queue and the scheduler selects a process from the head of the queue.
- A perfect real-life example of FCFS scheduling is buying tickets at a ticket counter.

## Calculating Average Waiting Time

For every scheduling algorithm, **average waiting time** is a crucial parameter used to judge its performance.

**AWT**, or **Average Waiting Time**, is the average of the waiting times of the processes in the queue while they wait for the scheduler to pick them for execution.

> Lower average waiting time means a better scheduling algorithm.

Consider the processes `P1`, `P2`, `P3`, and `P4`, arriving for execution in the same order with arrival time `0` and the burst times shown in the example below.

The average waiting time is **18.75 ms**.

For the given processes:

- waiting time for `P1` is `0`
- `P1` requires `21 ms` for completion, so waiting time for `P2` is `21 ms`
- waiting time for `P3` is execution time of `P1 + P2`, which is `(21 + 3) ms = 24 ms`
- waiting time for `P4` is the sum of execution times of `P1`, `P2`, and `P3`, which is `(21 + 3 + 6) ms = 30 ms`

## Problems with FCFS Scheduling

Below are some shortcomings of the FCFS scheduling algorithm:

- It is a non-preemptive algorithm, which means process priority does not matter.
- If a very low-priority process is being executed, such as a long routine backup task, and suddenly a high-priority process arrives, the high-priority process still has to wait.
- It does not provide optimal average waiting time.
- Parallel resource utilization is not possible, which leads to **convoy effect** and poor resource utilization for CPU, I/O, and other resources.

## What Is Convoy Effect?

Convoy effect is a situation where many processes that need to use a resource for a short time are blocked by one process holding that resource for a long time.

This essentially leads to poor utilization of resources and poor overall performance.

## Program for FCFS Scheduling

Here is a simple C++ program for processes with arrival time `0`.

In the program, we calculate the average waiting time and average turnaround time for a given array of burst times.

```cpp
/* Simple C++ program for implementation
of FCFS scheduling */

#include<iostream>

using namespace std;

// function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    // waiting time for first process will be 0
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  bt[i-1] + wt[i-1];
    }
}

// function to calculate turn around time
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

// function to calculate average time
void findAverageTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);

    // function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // display processes along with all details
    cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";

    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }

    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}

// main function
int main()
{
    // process ids
    int processes[] = { 1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];

    // burst time of all processes
    int  burst_time[] = {21, 3, 6, 2};

    findAverageTime(processes, n,  burst_time);

    return 0;
}
```

## Sample Output

```text
Processes Burst time Waiting time Turn around time
1 21 0 21
2 3 21 24
3 6 24 30
4 2 30 32
Average waiting time = 18.75
Average turn around time = 26.75
```

## Useful Formulae

- **Completion Time:** Time taken for the execution to complete, starting from arrival time.
- **Turn Around Time:** Time taken to complete after arrival. In simple words, it is the difference between the completion time and the arrival time.
- **Waiting Time:** Total time the process has to wait before its execution begins. It is the difference between the turnaround time and the burst time of the process.

For the program above, the arrival time has been considered as `0` for all processes. Try implementing a version with variable arrival times.

## Source

<http://www.guvi.in/hub/operating-system-tutorial/first-come-first-serve/>
