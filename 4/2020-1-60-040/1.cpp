#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, count = 0;
    cin >> T;
    long long int array[T];

    for(int i = 0; i < T; i++)
    {
        cin >> array[i];
    }

    for(int i = 0; i < T; i++)
    {
        count = 0;

        for(int j = 2; j <= array[i]; j++)
        {
            if(array[i] % j == 0)
            {
                count++;
            }
        }

        if(count == 1)
        {
            cout << "PRIME\n";
        }

        else
        {
            cout << "NOT PRIME";
        }
    }


}

