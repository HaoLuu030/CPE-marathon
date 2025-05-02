#include <iostream>

using namespace std;

long long current_move = 0;
int pegs[3] = {0};

void move(int disk, int start, int end)
{
    cout << "move disk " << disk << " from " << start << " to " << end << endl;
    pegs[start]--;
    pegs[end]++;
    current_move++;
}


void towerOfHanoi(int disk, int start, int end, int terminate_move)
{
    if (current_move >= terminate_move) return;
    if (disk == 1)
    {
        move(disk, start, end);
        return;
    }
    int aux = 3 - start - end;
    towerOfHanoi(disk - 1, start, aux, terminate_move);
    if (current_move >= terminate_move) return;
    move(disk, start, end);
    towerOfHanoi(disk - 1, aux, end, terminate_move);
}


int main()
{
    int n;
    long long m;
    while (cin >> n >> m)
    {
        if (m == 0 && n == 0) break;
        current_move = 0;
        pegs[0] = n;
        pegs[1] = 0;
        pegs[2] = 0;
        towerOfHanoi(n, 0, 2, m);
        if (n % 2 == 0)
        {
            cout << pegs[0] << ' ' << pegs[1] << ' ' << pegs[2] << endl;
        }
        // but for the odd number disks the order of aux and end pegs are reveresed
        // refer to a visual aid web to know more about this
        else
        {
            cout << pegs[0] << ' ' << pegs[2] << ' ' << pegs[1] << endl;
        }
    }
}