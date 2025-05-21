#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

const int c = 131071;
long long big_mod(int a, int b, int c)
{
    if (b == 0) return 1;
    int half = big_mod(a, b/2, c);
    if (b % 2 == 0)
    {
        half = half * half % c;
    }
    else
    {
        half = a*half*half % c;
    }

    return half;
}

int binary_to_decimal(string n)
{
    reverse(n.begin(), n.end());
    long long decimal = 0;
    for (int i = 1; i < n.size(); i++)
    {
        if (n[i] == 1)
        decimal = (decimal + big_mod(2, i - 1, c)) % c;
    }
    return decimal;
}




int main()
{
    string nu;
    string str = "";
    while (getline(cin, nu))
    {
        str += nu;
        size_t index = nu.size() - 1;
        if (nu[index] == '#')
        {
            long long n = binary_to_decimal(str);
            if (n == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
            str = "";
        }   
    }
    return 0;

}
