#include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>
// #include <vector>
using namespace std;
int main()
{
    int pages, frame, faults = 0;
    cout << "Enter the total no of pages\n ";
    cin >> pages;
    cout << "Enter the no of frames\n";
    cin >> frame;
    int string[pages];
    cout << "Enter the String:";
    for (int i = 0; i < pages; i++)
    {
        cin >> string[i];
    }

    // lru function
    vector<int> process;
    for (int i = 0; i < pages; i++)
    {
        auto x = find(process.begin(), process.end(), string[i]);
        if (x == process.end())
        {
            if (process.size() == frame)
            {
                process.erase(process.begin());
            }
            process.push_back(string[i]);
            faults++;
        }
        else
        {
            process.erase(x);
            process.push_back(string[i]);
        }
    }

    cout << "# of faults" << faults << "\n";

    return 0;
}
