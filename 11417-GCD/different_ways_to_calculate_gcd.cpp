#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == b) return a;
    else if (a > b) return gcd(a - b, b);
    else if (b < a) return gcd(b - a, a); // this can be replaced by the else clause only, but I want to write it out explicitly for better understanding
    return 0; // this line will never be reached, I just put it hear to silence the warning of C++
}

int gcd_extend(int a, int b)
{
    if (a % b == 0) return b;
    // b is always bigger since the remainder is always less than the divisor
    else return gcd_extend(b, a % b);
}

int main()
{
    int a, b;
    while (true)
    {
        cin >> a >> b;
        cout << "Gcd calculated by the original Euclidean algorithm: " << gcd(a, b) << endl;
        cout << "Gcd calculated by the extended Euclidean algorithm: " << gcd_extend(a, b) << endl;
    }
}
