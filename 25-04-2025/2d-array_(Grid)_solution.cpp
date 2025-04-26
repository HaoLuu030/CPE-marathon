// this approach uses a grid as a canvas
// to keep track of the "footprint"
// of the two guards by drawing on the canvas

// Pros: don't need to deal with a lot of branching logic
// Cons: waste a lot of memory since we need to create a 100 x 100 grid


#include <iostream>

using namespace std;


// constant values for readability
const int width = 100;
const int length = 100;
const int num_of_guards = 2;

int main() {
  // assigning memory for grid (this can be replaces by using array subscripting or vector)
  int **grid = new int *[length];
  for (int i = 0; i < length; i++) {
    grid[i] = new int[width];
  }
  // input night
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    // reset the grid for new night
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            grid[i][j] = 0;
        }
    }
    // "draw the rectangle for 2 guards by dots (points)"
    for (int i = 0; i < num_of_guards; i++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      // the order of the loops
      // should align with the order of the grid
      // in this problem: outside loop <-> vertical
      //                  insude loop <-> horizontal
      for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
          grid[i][j]++;
        }
      }
    }
    int strong, weak, no;
    // evaluate the dots to findout the strength of the guard
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < length; j++) {
        // the point(dot) was drawn once
        if (grid[i][j] == 1)
          weak++;
        // the point(dot) was drawn twice
        if (grid[i][j] == 2)
          strong++;
        // no point was drawn
        else
          no++;
      }
    }
    cout << "Night " << N << ": " << strong << weak << no << endl;
  }
  // memory clean up for pointers
  for (int i = 0; i < length; i++)
  {
    delete[] grid[width];
  }
  delete[] grid[length];
}
