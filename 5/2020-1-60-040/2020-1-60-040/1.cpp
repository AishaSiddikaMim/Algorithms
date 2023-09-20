#include<bits/stdc++.h>

using namespace std;

int coinChangeDp(int array[], int a, int K)
{
    int array1[a + 1][K + 1];

        for(int i = 0; i <= a; i++)
        {
            for(int j = 0; j <= K; j++)
            {
                if(j == 0)
                {
                    array1[i][j] = 0;
                }

                else if(array[i - 1] > j)
                {
                      array1[i][j] = array1[i - 1][j];
                }

                else if(i == 0)
                {
                    array1[i][j] = 10000000;

                }

                else
                    array1[i][j] = min(1 + array1[i][j - array[i - 1]], array1[i - 1][j]);
            }
        }

        if(array1[a][K] > 10000000)
        {
           return -1;
        }
        
        else
        {
        return array1[a][K];
        }
}

 int main()
    {
    int N, K;
    cin >> N;
    cin >> K;
    int array[N];

    for(int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    int a = sizeof(array) / sizeof(array[0]);
    
    cout << coinChangeDp (array, N ,K);
    }