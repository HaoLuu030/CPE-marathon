#include <iostream>
using namespace std;

int calculateArea(int, int, int, int);

int main() {
  // inputs
  const int langArea = 10000;
  int night, x1, y1, x2, y2, x3, y3, x4, y4;
  // areas
  int stronglyGuarded = 0;
  int weaklyGuarded = 0;
  int noGuard = 0;
  // enter number of nights
    cin >> night;
    for (int i = 0; i < night; i++) {
      // for each night:
      // reset area
      stronglyGuarded = 0;
      weaklyGuarded = 0;
      noGuard = 0;
      // enter the corners for 2 guards
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
      // check for intersection
      
        // calculate intersection
        // draw out cases to understand the logic
        int ix1 = (x1 > x3) ? x1 : x3;
        int ix2 = (x2 < x4) ? x2 : x4;
        int iy1 = (y1 > y3) ? y1 : y3;
        int iy2 = (y2 < y4) ? y2 : y4;
        stronglyGuarded = calculateArea(ix1, iy1, ix2, iy2);
      
      // calculate weakly guarded area
      weaklyGuarded = calculateArea(x1, y1, x2, y2) + calculateArea(x3, y3, x4, y4) -
                      stronglyGuarded * 2;
      // calculate no guarded area
      noGuard = langArea - weaklyGuarded - stronglyGuarded;

      cout << "Night " << i + 1 << ": " << stronglyGuarded << " "
           << weaklyGuarded << " " << noGuard << endl;
    }
  }

int calculateArea(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  return (x2 - x1) * (y2 - y1);
}
