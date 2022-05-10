#include <bits/stdc++.h>
using namespace std;

// seek time = track searching time + avg rotational latency + reed/write time

int main()
{
    int size;
    cin>>size;
    int arr[];
    int head = 30;

    int seek[5];
    for (int i = 0; i < 5; i++)
    {
        seek[i] = abs(arr[i] - head);
        head = arr[i];
    }

    // seek time
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << seek[i] << " ";
        sum += seek[i];
    }
    cout << "\n";

    // avg
    cout << "Avg seek time = " << sum / 5 << "\n";
    return 0;
}