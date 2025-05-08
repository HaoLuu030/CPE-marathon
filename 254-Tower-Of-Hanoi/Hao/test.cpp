#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>

using namespace std;

ostream& operator<<(std::ostream& os, __int128 n) {
    if (n == 0) return os << "0";
    std::string s;
    while (n > 0) {
        s += '0' + (n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

int main()
{
    std::array<__int128, 110> d;
    d[0] = 1;
    for (int i = 1; i <= 100; ++i)
        d[i] = d[i - 1] * 2;
    for (__int128 number : d)
    {
        cout << number << endl;
    }
}