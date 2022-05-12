#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cout << "Enter # of files\n";
    cin >> size;

    int head;
    cout << "Enter current head location\n";
    cin >> head;

    int files[size];
    cout << "Enter location of files\n";
    for (int i = 0; i < size; i++)
    {
        cin >> files[i];
    }

    int seek[size];
    int sum = 0;
    for (int i = 0; i < size; i++)
    {

        int min = INT_MAX;
        int value, index;
        for (int j = 0; j < size; j++)
        {
            value = abs(files[j] - head);
            if (min > value)
            {
                min = value;
                index = j;
            }
        }
        sum += min;
        head = files[index];
        files[index] = INT_MAX;
        seek[i] = min;
    }

    // seek time
    for (int i = 0; i < size; i++)
    {
        cout << seek[i] << " ";
    }
    cout << "\n";

    // avg
    cout << "Avg seek time = " << (double)sum << "\n";
    return 0;
}
