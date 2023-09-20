#include<bits/stdc++.h>

using namespace std;

int minimumCoins(int array[], int a, int K)
{
    if(K == 0)
    {
        return 0;
    }

    int output = INT_MAX;

    for(int i = 0; i < a; i++)
    {
        if(array[i] <= K)
        {
            int output1 = minimumCoins(array, a, K - array[i]);


            if(output1 != INT_MAX && output1 < output)
            {
                output = output1 + 1;
            }
        }
    }

    return output;
}

int main()
{
    int N, K;

    cin >> N >> K;

    int array[N];
    for(int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    int a = sizeof(array) / sizeof(array[0]);
    cout << minimumCoins(array, a, K);
    return 0;
}

