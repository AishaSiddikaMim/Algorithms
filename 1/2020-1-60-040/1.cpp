#include <bits/stdc++.h>

using namespace std;

int upperbound(int A[], int N, int S)
{
    int mid, low = 0, high = N;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(S == A[mid] && S < A[mid + 1])
        {
            return (mid + 1);
        }

        else if(S > A[mid])
        {
            low = mid + 1;
        }

        else
        {
            high = mid;
        }
    }
    return low;
}

int lowerbound(int A[], int N, int S)
{
    int mid, low = 0, high = N;
    while(low < high)
    {
        mid = (low + high) / 2;
        if((S == A[mid]) || (S > A[mid] && S < A[mid + 1]))
        {
            return mid;
        }

        else if (S > A[mid])
        {
            low = mid + 1;
        }

        else 
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int N, S;
    cin >> N >> S; 
    
    int A[N];
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    int a = upperbound(A, N, S);
    int b = lowerbound(A, N, S);
    
    if(S > A[0] && S < A[N])
    {
        cout << a << " " << b;
    }

    if(S < A[0] && S < A[N])
    {
        cout << a << " " << b;
    }

    if(S > A[N])
    {
    int size = sizeof(A) / sizeof(int);
    cout << size << " " << (b-1);
    }

    if(S < A[0])
    {
    cout << a << " " << 0;
    }
}