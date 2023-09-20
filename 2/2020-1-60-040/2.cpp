 #include<bits/stdc++.h>

using namespace std;

void mergeSort(int i, int j, int array[], int temp[])
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

int minDif(int array[], int N)
{


    int diff = INT_MAX;

    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
    {
        if(abs(array[i] - array[j]) < diff)
        {
            diff = abs(array[i] - array[j]);
        }
    }
    }

    return diff;
}

int main()
{
    int array[50], temp[50], N;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    mergeSort(0, N - 1, array, temp);
    cout<< minDif(array, N);
}