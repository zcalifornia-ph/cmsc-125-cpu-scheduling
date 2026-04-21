# Priority CPU Scheduling

In this tutorial, we will understand the priority scheduling algorithm, how it works, and its advantages and disadvantages.

In the **Shortest Job First (SJF)** scheduling algorithm, the priority of a process is generally the inverse of the CPU burst time, that is, the larger the burst time, the lower the priority of that process.

In **priority scheduling**, the priority is not always set as the inverse of CPU burst time. It can be set internally or externally. Scheduling is then done on the basis of process priority, where the most urgent process is executed first, followed by the ones with lower priority.

Processes with the same priority are executed in **FCFS** manner.

The priority of a process, when internally defined, can be decided based on:

- memory requirements
- time limits
- number of open files
- ratio of I/O burst to CPU burst

External priorities are set based on criteria outside the operating system, such as:

- the importance of the process
- funds paid for computer resource use
- market factors

## Types of Priority Scheduling Algorithm

Priority scheduling can be of two types:

### Preemptive Priority Scheduling

If the new process arriving at the ready queue has a higher priority than the currently running process, the CPU is preempted. This means the processing of the current process is stopped and the new higher-priority process gets the CPU for execution.

### Non-Preemptive Priority Scheduling

In non-preemptive priority scheduling, if a new process arrives with a higher priority than the current running process, the incoming process is put at the head of the ready queue. This means it will be processed after the execution of the current process finishes.

## Problem with Priority Scheduling Algorithm

In priority scheduling, there is a chance of **indefinite blocking**, or **starvation**.

A process is considered blocked when it is ready to run but has to wait for the CPU because some other process is currently running.

If new higher-priority processes keep coming into the ready queue, then lower-priority processes may have to wait for a very long time before getting CPU time for execution.

> In 1973, when the IBM 7904 machine was shut down at MIT, a low-priority process was found which was submitted in 1967 and had not yet been run.

## Using Aging Technique with Priority Scheduling

To prevent starvation, we can use the concept of **aging**, where we keep increasing the priority of a low-priority process based on its waiting time.

For example, if we decide the aging factor to be `0.5` for each day of waiting, then if a process with priority `20` (which is comparatively low priority) comes into the ready queue, after one day of waiting its priority becomes `19.5`, and so on.

Doing so ensures that no process has to wait indefinitely to get CPU time for processing.

## Implementing Priority Scheduling Algorithm in C++

Implementing priority scheduling is easy. All we have to do is sort the processes based on their priority and CPU burst time, and then apply the FCFS algorithm on them.

Here is the C++ code for priority scheduling:

```cpp
// Implementation of Priority scheduling algorithm
#include<bits/stdc++.h>
using namespace std;

struct Process
{
    // this is the process ID
    int pid;
    // the CPU burst time
    int bt;
    // priority of the process
    int priority;
};

// sort the processes based on priority
bool sortProcesses(Process a, Process b)
{
    return (a.priority > b.priority);
}

// Function to find the waiting time for all processes
void findWaitingTime(Process proc[], int n,
                     int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int  i = 1; i < n ; i++ )
        wt[i] =  proc[i-1].bt + wt[i-1] ;
}

// Function to calculate turn around time
void findTurnAroundTime( Process proc[], int n,
                         int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int  i = 0; i < n ; i++)
        tat[i] = proc[i].bt + wt[i];
}

//Function to calculate average time
void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    //Function to find waiting time of all processes
    findWaitingTime(proc, n, wt);

    //Function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);

    //Display processes along with all details
    cout << "\nProcesses  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";

    // Calculate total waiting time and total turn
    // around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t    " << wt[i]
             << "\t\t  " << tat[i] <<endl;
    }

    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n)
{
    // Sort processes by priority
    sort(proc, proc + n, sortProcesses);

    cout<< "Order in which processes gets executed \n";
    for (int  i = 0 ; i <  n; i++)
        cout << proc[i].pid <<" " ;

    findavgTime(proc, n);
}

// Driver code
int main()
{
    Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
    int n = sizeof proc / sizeof proc[0];
    priorityScheduling(proc, n);
    return 0;
}
```

There are many other scheduling algorithms that you should know about apart from priority scheduling. You will find all of them in this tutorial set.
