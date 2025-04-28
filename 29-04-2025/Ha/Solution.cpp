#include<bits/stdc++.h>
using namespace std;

long long binaryToDecimal(string s) {
    long long num = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        num = num * 2 + (c - '0');
    }
    return num;
}

int main()
{
    string s1, s2;
    long long n, res;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1;
        cin >> s2;
        long long a = binaryToDecimal(s1);
        long long b = binaryToDecimal(s2);
        cout << "Pair #" << i << ": ";
        if (__gcd(a, b) > 1)
        {
            cout << "All you need is love!" << endl;
        }
        else
        {
            cout << "Love is not all you need!" << endl;
        }
    }
}
