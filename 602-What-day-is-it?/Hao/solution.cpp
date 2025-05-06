#include <iostream>
#include <string>
using namespace std;

const int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string monthNames[13] = {
    "",     "January", "February",  "March",   "April",    "May",     "June",
    "July", "August",  "September", "October", "November", "December"};
const string daysInWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// count up to the year of 1752
// because england didn't
// switch until september
// which has passed feb
bool isLeapYear(int y) {
  return ((y <= 1752) ? (y % 4 == 0)
                     : (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)));
}

bool isValid(int m, int d, int y) {
  if (d < 1 || d > daysInMonth[m] + (m == 2 && isLeapYear(y)) || y < 1 || m < 1 || m > 12)
    return false;
  if (y == 1752 && m == 9 && d > 2 && d < 14)
    return false;
  return true;
}

bool isBeforeSwitch(int m, int d, int y) {
  if (y != 1752)
    return y < 1752;
  if (m != 9)
    return m < 9;
  return d <= 2;
}

int main() {
  int d, m, y;
  int day = 1;
  while (cin >> m >> d >> y) {
    if (m == 0 && d == 0 && y == 0)
      break;
    day = 1;
    if (isValid(m, d, y)) {
      // handle year
      for (int i = 1; i < y; i++) {
        day += 365 + (isLeapYear(i) ? 1 : 0);
      }
      for (int i = 1; i < m; i++) {
        day += daysInMonth[i];
        if (i == 2 && isLeapYear(y))
          day += 1;
      }
      day += d;
      // use the Gregorian calendar to represent the day in week
      if (isBeforeSwitch(m, d, y))
        day += 11;

      cout << monthNames[m] << ' ' << d << ", " << y << " is a "
           << daysInWeek[(day) % 7] << endl;
    } else {
      cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
    }
  }
  return 0;
}