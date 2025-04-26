#include <iostream>

using namespace std;

// function for gcd
int gcd(int a, int b)
{
    int remainder = a % b;
    if (remainder == 0) return b;
    else return gcd(b, remainder);
}   

int main()
{
    int N = 0;
    int G = 0;
    // only process the number if N != 0
    if (N != 0)
    {
        for (int i = 1; i < N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                G += gcd(i, j);
            }
        }
        cout << G << endl;
    }
}
