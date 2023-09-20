#include <bits/stdc++.h>

using namespace std;

struct temp
{
    int temp1, temp2;
};

struct activity
{
    int start, end;
};

int scheduling(activity array[], int low, int high)
{
    temp t;
    int pivot = array[(low + high) / 2].end;

    while(low <= high)
        {
        
        while(array[low].end < pivot)
        {
            low++;
        }
        
        while(array[high].end > pivot)
        {
            high--;
        }

        if(low <= high)
        {
            t.temp2 = array[low].end;
            t.temp1 = array[low].start;

            array[low].end = array[high].end;
            array[low].start = array[high].start;

            array[high].end = t.temp2;
            array[high].start = t.temp1;
            
            low++;
            high--;
        }
    }

    return low;
}

void sort(activity array[], int low, int high)
{
    int m = scheduling(array, low, high);

    if(low < m - 1)
    {
        sort(array, low, m - 1);
    }
    if(m < high)
    {
        sort(array, m, high);
    }
}

void max(activity array[], int N)
{
    int i = 0;
    int count = 1;

    for (int j = 1; j < N; j++)
    {
      if (array[j].start > array[i].end)
      {
        count++;
        i = j;
      }
    }

    cout << count;

}

int main()
{
        int N,j;

        cin >> N;
        activity array[N];

        for(int i = 0; i < N; i++)
        {
            j = i;
            cin >> array[i].start;
            cin >> array[j].end;
        }

        sort(array, 0, N - 1);
        max(array, N);

}