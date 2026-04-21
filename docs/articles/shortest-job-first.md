# Shortest Job First (SJF) Scheduling

Shortest Job First (SJF) scheduling works on the process with the shortest burst time or duration first.

- This is the best approach to minimize waiting time.
- This is used in batch systems.
- It is of two types:
  - non-preemptive
  - preemptive
- To successfully implement it, the burst time or duration of the processes should be known to the processor in advance, which is practically not feasible all the time.
- This scheduling algorithm is optimal if all jobs or processes are available at the same time, either because arrival time is `0` for all or because arrival time is the same for all.

## Non-Preemptive Shortest Job First

Consider the processes available in the ready queue for execution, with arrival time `0` for all and the given burst times.

The process `P4` is picked first because it has the shortest burst time, then `P2`, followed by `P3`, and at last `P1`.

We scheduled the same set of processes using the First Come First Serve algorithm in the previous tutorial and got an average waiting time of `18.75 ms`, whereas with SJF the average waiting time becomes `4.5 ms`.

## Problem with Non-Preemptive SJF

If arrival times are different, which means all the processes are not available in the ready queue at time `0`, then a short process may still have to wait for the current process to finish. In non-preemptive SJF, when a process with short duration arrives, the existing job is not halted or stopped just to execute the shorter job first.

This leads to the problem of **starvation**, where a shorter process may have to wait for a long time until the current longer process gets executed. This can be reduced using the concept of aging.

## Pre-emptive Shortest Job First

In preemptive SJF scheduling, jobs are put into the ready queue as they arrive, but as soon as a process with a shorter burst time arrives, the existing process is preempted and the shorter job is executed first.

The average waiting time is:

`((5 - 3) + (6 - 2) + (12 - 1)) / 4 = 8.75`

The average waiting time for preemptive shortest job first scheduling is less than both non-preemptive SJF scheduling and FCFS scheduling.

As `P1` arrives first, its execution starts immediately. After `1 ms`, process `P2` arrives with a burst time of `3 ms`, which is less than the remaining burst time of `P1`, so `P1` is preempted and `P2` is executed.

While `P2` is executing, `P3` arrives after `1 ms`, but it has a burst time greater than that of `P2`, so execution of `P2` continues. After another millisecond, `P4` arrives with a burst time of `2 ms`, so `P2` is preempted and `P4` is executed.

After the completion of `P4`, process `P2` is picked again and finishes, then `P3` is executed, and at last `P1`.

Pre-emptive SJF is also known as **Shortest Remaining Time First (SRTF)**, because at any given point in time, the job with the shortest remaining time is executed first.

## Program for SJF Scheduling

In the program below, we consider the arrival time of all jobs to be `0`.

The program sorts all jobs based on their burst time and then executes them one by one, just like in the FCFS scheduling program.

```cpp
// c++ program to implement Shortest Job first

#include<bits/stdc++.h>

using namespace std;

struct Process
{
   int pid;     // process ID
   int bt;      // burst Time
};

/*
    this function is used for sorting all
    processes in increasing order of burst time
*/
bool comparison(Process a, Process b)
{
    return (a.bt < b.bt);
}

// function to find the waiting time for all processes
void findWaitingTime(Process proc[], int n, int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] = proc[i-1].bt + wt[i-1] ;
    }
}

// function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}

// function to calculate average time
void findAverageTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // function to find waiting time of all processes
    findWaitingTime(proc, n, wt);

    // function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);

    // display processes along with all details
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n";

    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t " << wt[i]
             << "\t\t " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

// main function
int main()
{
    Process proc[] = {{1, 21}, {2, 3}, {3, 6}, {4, 2}};
    int n = sizeof proc / sizeof proc[0];

    // sorting processes by burst time.
    sort(proc, proc + n, comparison);

    cout << "Order in which process gets executed\n";
    for (int i = 0 ; i < n; i++)
    {
        cout << proc[i].pid <<" ";
    }

    findAverageTime(proc, n);

    return 0;
}
```

## Sample Output

```text
Order in which process gets executed
4 2 3 1

Processes Burst time Waiting time Turn around time
4 2 0 2
2 3 2 5
3 6 5 11
1 21 11 32
Average waiting time = 4.5
Average turn around time = 12.5
```

Try implementing the program for SJF with variable arrival times for different jobs yourself.
