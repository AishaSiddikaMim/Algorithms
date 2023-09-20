#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

void dp(char* M, char* N, int m, int n)
{
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }

            else if (M[i - 1] == N[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }

            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    int index = L[m][n];

    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
        if (M[i - 1] == N[j - 1]) 
        {
            lcs[index - 1]= M[i - 1];
            i--;
            j--;
            index--;
        }

        else if (L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }
        
        else
        {
            j--;
        }
    }
    cout << L[m][n]<<"\n"<< lcs;
}

int main()
{
    char M[100];
    char N[100];

    cin >> M;
    cin >> N;

    int m = strlen(M);
    int n = strlen(N);
    
    dp(M, N, m, n);
    return 0;
}