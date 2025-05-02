#include <iostream>

using namespace std;


// can use int based on the contraint
int big_mod(int a, int b, int c)
{
    // break the exponent (aka b) down to a smaller number
    // base case b = 0
    if (b == 0) return (1 % c);
    if (b % 2 == 0)
    {
        int half = big_mod(a, b / 2, c) % c;
        return (half * half) % c;
    }
    else return ((big_mod(a, b - 1, c) % c) * (a % c)) % c;
}



int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        cout << big_mod(a, b, c) << endl;
    }
}