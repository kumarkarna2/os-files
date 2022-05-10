#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    cout << "Enter # of processes"
         << "\n";
    cin >> num;
    int bt[num];
    int wait[num];
    wait[0] = 0;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter burst time of process : " << i + 1
             << "\n";
        cin >> bt[i];
    }

    sort(bt, bt + num);

    wait[0] = 0;
    for (int i = 1; i < num; i++)
    {
        wait[i] = wait[i - 1] + bt[i - 1];
    }

    // avg waiting time
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < num; i++)
    {
        total_wt += wait[i];
    }
    cout << "avg waiting time is " << total_wt / num << endl;

    // avg TAT //tat=wait[i]+bt[i]
    int tat[num];

    for (int i = 0; i < num; i++)
    {
        tat[i] = wait[i] + bt[i];
        total_tat += tat[i];
    }
    cout << "avg turn around time is " << total_tat / num << "\n";

    return 0;
}