#include <bits/stdc++.h>
#include <String.h>
using namespace std;

void occurance(string T, string P)
{
    int n = T.size();
    int m = P.size();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i + j >= n || P[j] != T[i + j])
            {
                break;
            }
            
            if(j == m - 1)
            {
                cout << i << ' ';
            }
        }

    }
}

int main()
{
    char T[1000000], P[1000];
    cin >> T;
    cin >> P;
    occurance(T, P);
}