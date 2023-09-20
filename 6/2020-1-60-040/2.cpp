#include <bits/stdc++.h>

using namespace std;

int main()
{
        int M, N;

        cin >> M;
        cin >> N;

        int array[M][N];
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> array[i][j];
            }
        }

        int x, y, min;
        x = M + 1;
        y = N + 2;
       
        int array1[x][y];

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < 1; j++)
            {
               array1[i][j] = INT_MAX;
            }
        }

        for(int i = 0; i < 1; i++)
        {
            for(int j = 1; j < y - 1; j++)
            {
                array1[i][j] = 0;
            }
        }

        for(int i = 0; i < x; i++) 
        {
            for(int j = y - 1; j < y; j++) 
            {
                array1[i][j] = INT_MAX;
            }
        }

        for(int i = 1; i < x; i++)
        {
            for(int j = 1; j < y - 1; j++)
            {
                if(array1[i - 1][j - 1] <= array1[i - 1][j] && array1[i - 1][j - 1] <= array1[i - 1][j + 1])
                {
                    min = array1[i - 1][j - 1];
                }

                else if(array1[i - 1][j] <= array1[i - 1][j - 1] && array1[i-1][j] <= array1[i - 1][j + 1])
                {
                    min=array1[i - 1][j];
                }

                else
                {
                    min = array1[i - 1][j + 1];
                }

                array1[i][j] = array[i - 1][j - 1] + min;
            }
        }

        int result = INT_MAX;

        for(int i = x - 1; i < x; i++)
        { 
            for(int j = 1; j < y - 1; j++)
            {
                if(result > array1[i][j])
                {
                    result = array1[i][j];
                }
            }
        }
        cout << result;
}