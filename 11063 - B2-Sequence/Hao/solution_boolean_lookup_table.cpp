#include <iostream>

using namespace std;

int main()
{
    int N;
    bool isB2 = true;
    int testCase = 0;
    while (cin >> N)
    {
        testCase++;
        isB2 = true;
        if (N < 2)
        {
            isB2 = false;
        }
        bool repeated[20001] = {false};
        int arr[N];
        // take input
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        // check to see if the sequence is an increasing sequence
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i] >= arr[i + 1])
            {
                isB2 = false;
                break;
            }
        }
        // check to see if all numbers are larger or equal to one
        if(!isB2 || arr[0] < 1)
        {
            cout << "Case #" << testCase << ": It is not a B2-Sequence.\n\n";
            continue; 
        }
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                // found repeated number
                if (repeated[arr[i] + arr[j]])
                {
                    isB2 = false;
                    break;
                }
                // otherwise mark the element in the reference table as true
                repeated[arr[i] + arr[j]] = true;
            }
        }
        cout << "Case #" << testCase << ": " << "It is" << (isB2 ? "" : " not") << " a B2-Sequence.\n\n";
    }
}