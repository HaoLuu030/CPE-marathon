#include <cmath>
#include <iostream>
#include <string>
using namespace std;

const int DEGREE = 8;

int main() {
  string s = "";
  int input = 0;
  int first = 0;
  while (true) {
    first = 0;
    s = "";
    for (int i = DEGREE; i >= 1; i--) {
      cin >> input;
      if (input == 0)
        continue;
      // logic for the sign
      if (first == 0) {
        // for the first element
        first = i;
        s += (input > 0 ? "" : "-");
      } else {
        s += (input > 0 ? " + " : " - ");
      }
      // order: add coefficient -> add 'x' -> add carret along with exponents
      s += (input != 1 && input != -1 ? to_string(abs(input)) : "") + "x" + (i != 1 ? "^" + to_string(i) : "");
    }
    // last term
    cin >> input;
    if (input != 0)
    {
      if (s.empty())
      {
        // case: there's only one consant non-zero term
        s += (input < 0 ? "-" : "") +to_string(abs(input));
      }
      else
      {
        s += (input > 0 ? " + " : " - ") + to_string(abs(input));
      }
    }
    // edge case for 0 0 0 0 0 0 0 0 0
    if (s.empty())
      s = "0";
    cout << s << endl;
  }
}