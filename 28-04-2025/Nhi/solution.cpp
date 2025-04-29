#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int binaryToDecimal(string s)
{
    int num = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '0')
        {
            num += pow(2, i);
        }
    }

    return num;
}

// Another way
// int binaryToDecimal(string s)
// {
//     return stoi(binary, nullptr, 2);
// }

int GCD(int a, int b)
{
    return (b == 0) ? a : GCD(b, a % b);
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string S1, S2;
        cin >> S1 >> S2;
        int num1 = binaryToDecimal(S1);
        int num2 = binaryToDecimal(S2);
        int L = GCD(num1, num2);
        cout << "Pair #" << i + 1 << ": " << ((L == 1) ? "Love is not all we need" : "All you need is love" ) << endl;
    }

    return 0;
}
