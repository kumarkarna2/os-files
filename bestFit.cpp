#include <bits/stdc++.h>
using namespace std;

int main()
{

    int nFiles, nBlock;

    cout << "Enter # of blocks"
         << "\n";
    cin >> nBlock;

    cout << "Enter # of Files"
         << "\n";
    cin >> nFiles;

    int file[nFiles], block[nBlock];
    for (int i = 0; i < nBlock; i++)
    {
        cout << "Enter Size Of the Block " << i + 1 << "\n";
        cin >> block[i];
    }
    for (int i = 0; i < nFiles; i++)
    {
        cout << "Enter Size Of the file " << i + 1 << "\n";
        cin >> file[i];
    }

    int remSize[nFiles];

    // calculation part
    int allocate[nFiles];
    memset(allocate, -1, nFiles); // fill value = -1, from 0 to size in array

    // first fit
    //  for (int i = 0; i < nFiles; i++)
    //  {
    //      for (int j = 0; j < nBlock; j++)
    //      {
    //          if (block[j] >= file[i])
    //          {
    //              allocate[i] = j;
    //              block[j] -= file[i];
    //              remSize[i] = block[j];
    //              break;
    //          }
    //      }
    //  }

    // best fit
    for (int i = 0; i < nFiles; i++)
    {
        int index = -1;
        for (int j = 0; j < nBlock; j++)
        {
            if (block[j] >= file[i])
            {
                if (index == -1)
                    index = j;
                else if (block[index] > block[j])
                    index = j;
            }
        }

        if (index != -1)
        {
            allocate[i] = index;
            block[index] -= file[i];
            remSize[i] = block[index];
        }
    }

    // check whether a process is allocated
    for (int i = 0; i < nFiles; i++)
    {
        cout << "file no: " << i + 1 << "\n";
        cout << "File size " << file[i]
             << "\n";
        if (allocate[i] != -1)
        {
            cout << "Block # = " << allocate[i] + 1 << "\n";
        }
        else
        {
            cout << "Not Allocated"
                 << "\n";
        }
        cout << "Remaining Block size " << remSize[i] << "\n";
    }

    return 0;
}