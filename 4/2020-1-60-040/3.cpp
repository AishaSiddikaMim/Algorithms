#include <bits/stdc++.h>

using namespace std;

void KMP(char* P, int m, int* array)
{
    int length = 0;

    array[0] = 0;
    int i = 1;

    while(i < m)
    {
        if(P[i] == P[length])
        {
            length++;
            array[i] = length;
            i++;
        }

        else
        {
            if(length != 0)
            {
                length = array[length - 1];
            }

            else
            {
                array[i] = 0;
                i++;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    char P[100000];
    gets(P);

    int m = strlen(P);
    int array[m];
    KMP(P, m, array);
}