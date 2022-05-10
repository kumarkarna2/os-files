#include <bits/stdc++.h>
using namespace std;

void fcfs(int process[], int wait[], int n)
{
    wait[0] = 0;
    int TAT[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time of process " << i + 1 << endl;
        cin >> process[i];
    }
    int avgWT = 0, avgTAT = 0;

    // calcilating waiting time for different processes
    // waiting time = burst time + waiting time of previous process
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            wait[i] += process[j];
        }
    }

    // calculating TAT
    // burst time + waiting time
    for (int i = 0; i < n; i++)
    {
        TAT[i] = process[i] + wait[i];
        avgWT += wait[i];
        avgTAT += TAT[i];
    }

    avgWT /= n;  // calculating average wait time
    avgTAT /= n; // calculating average turn around time

    cout << "In FCFS average waiting time is " << avgWT << "\n";
    cout << "In FCFS average turn around time is " << avgTAT << "\n";
}

void sjf(int process[], int wait[], int n)
{
    wait[0] = 0;
    sort(process, process + n);
    
    for (int i = 1; i < n; i++)
    {
        wait[i] += process[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << wait[i] << "\t";
    }
}

int main()
{
    int n;
    cout << "Enter Number of processes"
         << "\n";
    cin >> n;
    int process[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time for P"
             << i + 1
             << "\n ";
        cin >>
            process[i];
    }
    int wait[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter waiting time for P"
    //          << i + 1
    //          << "\n ";
    //     cin >>
    //         wait[i];
    // }

    cout << "Choose what do you want to perform"
         << "\n"
         << "1. FCFS Scheduling\n2. SJF Scheduling\n3. SRTF Scheduling\n";
    int choice;
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            fcfs(process, wait, n);
            break;
        case 2:
            sjf(process, wait, n);
        default:
            break;
        }
    }
    return 0;
}