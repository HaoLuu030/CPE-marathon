#include <iostream>
using namespace std;


static const int int_max = 20001; 

int main()
{
    int N, test_case = 0;
    bool isB2;
    while(cin >> N)
    {
        isB2 = true;
        test_case++;
        if (N < 2) isB2 = false;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                isB2 = false;
                break;
            }
        }
        if (arr[0] < 1) isB2 = false;
        if (!isB2)
        {
            cout << "Case #" << test_case << ": " << "It is not a B2-Sequence.\n\n";
            continue; 
        }
        bool duplicate[int_max] = {false};
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                if(duplicate[arr[i] + arr[j]] == true)
                {
                    isB2 = false;
                    break;
                }
                duplicate[arr[i] + arr[j]] = true;
            }
        }
        cout << "Case #" << test_case << ": " << "It is" << (isB2 ? "" : " not") << " a B2-Sequence.\n\n";
    }
}