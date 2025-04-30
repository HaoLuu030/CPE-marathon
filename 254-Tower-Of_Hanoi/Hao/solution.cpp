#include <iostream>
#include <string>
using namespace std;

// global variable to track move and number of disks on each rod
int move__ = 0;
int rods[3] = {0};

// for more details about the algorithm of the tower of hanoi problem
// please refer to the algorithm cpp file in the parent directory
void towerOfHanoi(int n, int start, int end, int terminate_move) {
  // terminate when the number of moves is reached
  if (move__ >= terminate_move)
    return;
  if (n == 1) {
    move__++;
    rods[start - 1]--;
    rods[end - 1]++;
    return;
  }
  int auxiliary = 6 - start - end;
  towerOfHanoi(n - 1, start, auxiliary, terminate_move);
  if (move__ >= terminate_move)
    return;
  move__++;
  rods[start - 1]--;
  rods[end - 1]++;
  towerOfHanoi(n - 1, auxiliary, end, terminate_move);
}

int main() {
    int a, b;
    while(cin >> a >> b)
    {
        if (a == 0 && b == 0) break;
        move__ = 0;
        rods[0] = a;
        rods[1] = 0;
        rods[2] = 0;
        towerOfHanoi(a, 1, 3, b);
        cout << rods[0] << ' ' << rods[1] << ' ' << rods[2] << endl;
    }
    return 0;
}