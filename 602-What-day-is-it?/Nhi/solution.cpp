#include <iostream>
#include <string>
using namespace std;

string dayInWeek[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
string month[] = {"", "January","February","March","April","May","June",
    "July","August","September","October","November","December"};
int dayInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year) // return 1 if this year is a leap year
{
    return (year <= 1752) ? (year % 4 == 0) : 
    (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool isValid(int d, int m, int y)
{
    if (d < 1 || m < 1 || m > 12 || y < 1 || 
        (y == 1752 && m == 9 && d > 2 && d < 14) ||
        (d > dayInMonth[m] + (m == 2 && isLeapYear(y)))) 
            return false;
    return true;
}

int main()
{
    int d, m, y;
    while (cin >> m >> d >> y)
    {
        if (d == 0 && m == 0 && y == 0) break;
        if (!isValid(d, m, y))
        {
            cout << m << "/" << d << "/" << y << " is an invalid date." << endl;
            continue;
        }
        int w = 1;

        for (int i = 1; i < y; i++)
        {
            w += 365 + isLeapYear(i);
        }

        for (int i = 1; i < m; i++)
        {
            w += dayInMonth[i];
            if (i == 2) w += isLeapYear(y);
        }

        if ((y < 1752) || (y == 1752 && m < 9) || (y == 1752 && m == 9 && d < 3))
        {
            w += 11;
        }

        w += d;

        cout << month[m] << " " << d
        << ", " << y << " is a " << dayInWeek[w % 7] << endl;

    }

    return 0;
}
