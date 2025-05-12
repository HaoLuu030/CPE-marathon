#include <iostream>

using namespace std;

void printMove(int disk, int start, int end)
{
    cout << "Moving disk " << disk << " from " << start << " to " << end << endl; 
}

void towerOfHanoi(int disk, int start, int end)
{
    // base case: when there's only one disk
    if (disk == 1)
    {
        printMove(disk, start, end);
        return;
    }
    // otherwise: move n - 1 disks from the auxiliary rod
    int aux = 6 - start - end;
    towerOfHanoi(disk - 1, start, aux);
    // move the base disk to the end rod;
    printMove(disk, start, end);
    // move n - 1 disk from aux to end
    towerOfHanoi(disk - 1, aux, end);
}


int main()
{
    towerOfHanoi(3, 1, 3);
}