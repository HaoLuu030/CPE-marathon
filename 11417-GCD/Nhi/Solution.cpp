#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    // Euclidean algorithm
    return (b == 0) ? a : GCD(b, a % b);
}

// Another way to calculate the greatest common divisor
// int GCD(int a, int b)
// {
//      return (a == b) ? a : (a > b) ? GCD(b, a - b) : GCD(b - a, a);
// }

int main()
{
    int N;
    while(cin >> N)
    {
        if (N == 0) break; // If N == 0 , the input is terminated

        // Copy and paste from the question 
        int G = 0;
        for (int i = 1; i < N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                G += GCD(i, j);
            }
        }
        cout << G << endl;

    }
    return 0;
}
