#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cout << "Enter # of files\n";
    cin >> size;

    int files[size];
    cout<<"Enter location of files\n";
    for (int i = 0; i < size; i++)
    {
        cin>>files[i];
    }

    int head;
    cout << "Enter current head location\n";
    cin >> head;

    int seek[size];

    // sorting in increasing order of location
    sort(files, files + size);
    for (int i = 0; i < size; i++)
    {
        seek[i] = abs(files[i] - head);
        head = files[i];
    }

    // seek time
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        cout << seek[i] << " ";
        sum += seek[i];
    }
    cout << "\n";

    // avg
    cout << "Avg seek time = " << sum / 5 << "\n";
    return 0;
}