#include <bits/stdc++.h>

using namespace std;

void Merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high - low + 1];
	
    i = low;
	k = 0;
	j = mid + 1;

while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}

		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

void MergeSort(int *a, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;

		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, high, mid);
	}
}

int rem(int array[], int n)
{
    if (n == 0||n == 1)
    {
        return n;
    }

    int j = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] != array[i + 1])
        {
            array[j++] = array[i];
        }

    }

    array[j++] = array[n - 1];

    return j;
}

int MCM(int n, int p[])
{
    int c[n][n] = {0};
    int m[n][n] = {0};

    int j, min, q;

    for(int b = 1; b < n - 1; b++)
    {
        for(int i = 1; i < n - b; i++)
        {
            j = i + b;
            min = INT_MAX;

            for(int k = 1; k <= j - 1; k++)
            {
                q = c[i][k] + c[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                if(q < min)
                {
                    min = q;
                    m[i][j] = k;
                }
            }
            c[i][j] = min;
        }
    }
    return c[1][n - 1];
}

int main () 
{
        int N, a;
        cin >> N;

        int n = 2 * N;

        int array[n];
        for(int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        MergeSort(array, 0, n - 1);
        a  = rem(array, n);
        cout << MCM(a,array);

    return 0;
}