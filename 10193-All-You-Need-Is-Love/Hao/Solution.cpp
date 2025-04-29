
#include <iostream>
#include <string>
using namespace std;

// make shift function for gcd
int gcd (int a, int b)
{
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

// make shift function for power
// has been updated to achieve log n time
int pow(int b, int e)
{
    if (e == 0) return 1;
    int half = pow(b, e / 2);
    half = half * half;
    if (e % 2 == 1) half = b * half;
    return half;
}

// we can either do this
// or we can use stoi with specialized
// paramter to convert the string to
// binary directly
int string_to_decimal(string s)
{
    int sum = 0;
    // reverse the string
    // so the summing direction
    // aligns with way we convert a binary
    // to a decimal number
    for (int i = 0; i < s.size() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = temp;
    }
    // calculate sum
    for (int i = 0; i < s.size(); i++)
    {
        sum += pow(2, i) * (s[i] - '0');
    }
    return sum;
}



int main()
{
    int N;
    string S1, S2;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S1 >> S2;
        int L = gcd(string_to_decimal(S1), string_to_decimal(S2));
        cout << "Pair: " << i + 1 << ": " << ((L > 1) ? "All you need is love!" : "Love is not all you need!") << endl;
    }
}
