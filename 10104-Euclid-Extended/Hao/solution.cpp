#include <iostream>

using namespace std;

// keep x and y as the global variable for modification
int x, y;
int extendedEuclid(int a, int b, int& x, int& y)
{
    // base case
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    // create x1 and y1 for recursive calls
    int x1, y1;
    int gcd = extendedEuclid(b, a % b, x1, y1);
    // this can be proven using the basic version of euclid algorithm
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}


int main()
{
    int a, b;
    while(cin >> a >> b)
    {
        int gcd = extendedEuclid(a, b, x, y);
        cout << x << ' ' << y << ' ' << gcd << endl;
    }
}