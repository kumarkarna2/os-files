#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size; //# process
    cout << "Enter number of processes"
         << "\n";
    cin >> size;
    int arr[size];
    int wait[size];
    wait[0] = 0;
    int TAT[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter burst time of process " << i + 1 << endl;
        cin >> arr[i];
    }
    float avgWT = 0, avgTAT = 0;

    // calcilating waiting time for different processes
    // waiting time = burst time + waiting time of previous process
    for (int i = 1; i <= size; i++)
    {
        wait[i] = wait[i - 1] + arr[i - 1];
    }

    // calculating TAT
    // burst time + waiting time
    for (int i = 0; i < size; i++)
    {
        TAT[i] = arr[i] + wait[i];
        avgWT += wait[i];
        avgTAT += TAT[i];
    }

    avgWT /= size;  // calculating average wait time
    avgTAT /= size; // calculating average turn around time

    cout << "Average waiting time is " << avgWT << "\n";
    cout << "Average turn around time is " << avgTAT << "\n";

    return 0;
}