#include <iostream>

using namespace std;

int x, y;
int extendedEuclid(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclid(b, a % b, x1, y1);
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