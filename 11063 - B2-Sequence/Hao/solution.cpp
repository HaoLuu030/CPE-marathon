#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int testCase = 0;
    int N;
    bool isB2 = true;
    while(cin >> N)
    {
        testCase++;
        isB2 = true;
        vector<int> v(N);
        vector<int> copy;
        vector<int> result;
        if (N < 2 || N > 100)
        {
            isB2 = false;
        }
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
        }
        copy = v;
        sort(copy.begin(), copy.end());
        auto it = unique(copy.begin(), copy.end());
        copy.erase(it, copy.end());
        // has duplicate
        if (v.size() != copy.size())
        {
            cout << "Case #" << testCase << ": " << "It is not a B2-Sequence.\n" << endl;
            continue;
        }
        // not sorted
        for (int i = 0; i < N; i++)
        {
            if (v[i] != copy[i])
            {
                isB2 = false;
                break;
            }
        }
        // has negative numbers
        for (int i = 0; i < N; i++)
        {
            if (v[i] < 1)
            {
                isB2 = false;
                break;
            }
        }
        if(!isB2)
        {
            cout << "Case #" << testCase << ": " << "It is not a B2-Sequence.\n" << endl;
            continue;
        }
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                result.push_back(v[i] + v[j]);
            }
        }
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size() - 1; i++)
        {
            if (result[i] == result[i + 1])
            {
                isB2 = false;
                break;
            }
        }
        cout << "Case #" << testCase << ": " << "It is" << ((isB2) ? " " : " not ") << "a B2-Sequence.\n" << endl; 
    }
}