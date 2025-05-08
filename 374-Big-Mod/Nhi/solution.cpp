#include <iostream>
using namespace std;

long long bigMod(int B, int P, int M)
{
    if (P == 0) return 1;
    long long half = bigMod(B, P / 2, M);
    if (P % 2 == 0)
    {
        return (half*half) % M;
    }
    else
    {
        return B * half * half % M;
    }
}

int main()
{
    long long B, P, M;
    while (cin >> B >> P >> M)
    {
        cout << bigMod(B, P, M) << endl;
    }
    return 0;
}
