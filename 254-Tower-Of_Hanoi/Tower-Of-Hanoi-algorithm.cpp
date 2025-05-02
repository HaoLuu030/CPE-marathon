#include <iostream>

using namespace std;

// the core idea to solving this problem:
// assuming we have 3 rods: start, end, and auxiliary rods
// move the largest disk from start to end rod
//      in order to do this, we move the top n - 1 disks to the auxiliary rod
//          in order to do this, we move the top n - 2 disks from the start rod to the end rod (it's an auxiliary rod in this case)
//          so that's where the recursion blends in beautifully
// repeat the process until we reach the base case



// the function means moving the top disk from start to end rod
void printMove(int d, int start, int end)
{
    cout << "Moving disk " << d  << " from " << start << " to " << end << endl;
}

void hanoi(int n, int start, int end)
{
    // if there's only one disk (as base case)
    if (n == 1)
    {
        printMove(n, start, end);
        return;
    }
    // since rods are represented as rod 1 rod 2, and rod 3
    // so the total of 3 rods are 6
    // move n - 1 disks to axiliary rod
    int auxiliary = 6 - start - end;
    hanoi(n - 1, start, auxiliary);
    // move the top disk from start to end
    printMove(n, start, end);
    // move the n - 1 disks to the end rod
    hanoi(n - 1, auxiliary, end);
}

int main()
{
    hanoi(3, 1, 3);
}
