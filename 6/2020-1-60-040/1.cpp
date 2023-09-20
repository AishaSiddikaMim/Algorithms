#include <bits/stdc++.h>

using namespace std;

int LongestIncreasingSubsequence(int array[], int a)
{
    int lIS[a];

    lIS[0] = 1;

    for (int i = 1; i < a; i++)
    {
        lIS[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (array[i] > array[j] && lIS[i] < lIS[j] + 1)
            {
                lIS[i] = lIS[j] + 1;
            }
        }
    }
    return *max_element(lIS, lIS + a);
}

int main()
{
    int N;
    cin >> N;

    int array[N];
    for(int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    int a = sizeof(array) / sizeof(array[0]);
    
    cout << LongestIncreasingSubsequence(array, a);

    return 0;
}