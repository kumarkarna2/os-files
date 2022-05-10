#include <bits/stdc++.h>
using namespace std;
void process();
// global declaration
int i = 0,
    j = 1 - i;
int turn;
bool flag[2];

void cs(int i)
{
    cout << "P" << i + 1 << " in critical section"
         << "\n";
}
void process()
{
    do
    {

        flag[i] = true;
        turn = j;
        while (flag[j] && turn == j)
            ;
        cs(i);
        flag[i] = false;
    } while (true);

    do
    {

        flag[j] = true;
        turn = i;
        while (flag[i] && turn == i)
            ;
        cs(j);
        flag[j] = false;

    } while (true);
}

// void process2()
// {
//     while (1)
//     {

//         flag[j] = true;
//         turn = i;
//         while (turn == i && flag[i])
//             ;
//         cs(j);
//         flag[i] = false;
//         process1();
//     }
// }

int main()
{
    process();
    return 0;
}