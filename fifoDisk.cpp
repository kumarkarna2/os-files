#include <bits/stdc++.h>
using namespace std;

// seek time = track searching time + avg rotational latency + reed/write time

int main()
{
    int size;
    cout << "Enter # of files\n";
    cin >> size;
    int process[size];

    int head;
    cout << "Enter current head location\n";
    cin >> head;

    cout << "Enter location of files\n";
    for (int i = 0; i < size; i++)
    {
        cin >> process[i];
    }

    // seek time
    int seek[size];
    for (int i = 0; i < size; i++)
    {
        seek[i] = abs(process[i] - head);
        head = process[i];
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        cout << seek[i] << " ";
        sum += seek[i];
    }
    cout << "\n";

    // avg
    cout << "Avg seek time = " << (double)sum / size << "\n";
    return 0;
}