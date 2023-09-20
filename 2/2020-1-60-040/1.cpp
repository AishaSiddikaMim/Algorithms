#include<bits/stdc++.h>

using namespace std;

void mergeSort(int i, int j, float array[], float temp[])
{
    if(i >= j)
    {
        return;
    }


    int mid = (i + j) / 2;

    mergeSort(i, mid, array, temp);
    mergeSort(mid + 1, j, array, temp);

    int left = i;
    int right = mid + 1;

    for(int k = i ; k <= j; k++)
    {
        if(left == mid + 1)
        {
            temp[k] = array[right];
            right = right + 1;
        }

        else if(right == j + 1)
        {
            temp[k] = array[left];
            left = left + 1;
        }

        else if(array[left] < array[right])
        {
            temp[k] = array[left];
            left = left + 1;
        }

        else
        {
            temp[k] = array[right];
            right = right + 1;
        }
    }

    for(int k = i; k <= j; k++)
    {
        array[k] = temp[k];
    }
}

int func(float array[], int N, int pos)
{
    float temp1, temp2, array2[N];
    float temp[50];
    for(int i = 0; i < N; i++)
    {
        temp1 = array[i];
        array2[i] = temp1;
    }

    temp2 = array2[pos];
    mergeSort(0, N-1, array, temp);

    for(int i = 0; i < N; i++)
    {
        if(temp2 == array[i])
        {
            cout << i;
        }
    }
}

int main()
{
    float array[50], temp[50];
    int N, pos;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    cin >> pos;
    func(array, N, pos);
}