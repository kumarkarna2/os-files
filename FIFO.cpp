#include <bits/stdc++.h>
using namespace std;

int main()
{
    int frames, noProcess, noFaults;
    cout << "Enter # of frames\n";
    cin >> frames;
    cout << "Enter # of process\n";
    cin >> noProcess;

    int process[noProcess];
    cout << "Enter strings\n";
    for (int i = 0; i < noProcess; i++)
    {
        cin >> process[i];
    }

    unordered_set<int> set;
    queue<int> queue;

    for (int i = 0; i < noProcess; i++)
    {
        if (set.size() < frames)
        {
            if (set.find(process[i]) == set.end())
            {
                set.insert(process[i]);
                noFaults++;
                queue.push(process[i]);
            }
        }

        else
        {
            if (set.find(process[i]) == set.end())
            {
                int file = queue.front();
                queue.pop();
                set.erase(file);

                set.insert(process[i]);
                queue.push(process[i]);
                noFaults++;
            }
        }
    }

    cout << "# of page fault = " << noFaults;
    return 0;
}