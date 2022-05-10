#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int priority;
};

bool sort_process(process p1, process p2)
{
    return (p1.priority > p2.priority);
}

void wait_time(process p[], int size, int wait[])
{
    wait[0] = 0;

    for (int i = 0; i < size; i++)
    {
        wait[i] = wait[i - 1] + p[i - 1].bt;
    }
}
void cal_tat(process p[], int size, int tat[], int wait[])
{
    for (int i = 0; i < size; i++)
    {
        tat[i] = wait[i] + p[i].bt;
    }
}

int main()
{
    int size;
    cin >> size;
    process p[size];
    for (int i = 0; i < size; i++)
    {
        cin >> p[i].pid >> p[i].at >> p[i].bt >> p[i].priority;
    }

    // for (int i = 0; i < size; i++)
    // {
    //     cout << p[i].pid << p[i].at << p[i].bt << p[i].priority;
    // }
    sort(p, p + size, sort_process);

    cout << "Order in which processes gets executed \n";
    for (int i = 0; i < size; i++)
        cout << p[i].pid << " ";
    int wait[size], tat[size];

    wait_time(p, size, wait);
    cal_tat(p, size, tat, wait);

    return 0;
}