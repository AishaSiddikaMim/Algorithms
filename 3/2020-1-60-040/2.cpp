#include <bits/stdc++.h>

using namespace std;

struct cart
{
    int cart1, cart2;
};

struct element
{
    int b, w;
};

int knapsack(element item[], int array[], int low, int high)
{
    cart finalcart;
    int temp;
    int pivot = array[(low + high) / 2];

    while(low <= high)
    {
        while(array[low] > pivot)
        {
            low++;
        }

        while(array[high < pivot])
        {
            high--;
        }

        if(low <= high)
        {
            temp = array[low];
            finalcart.cart1 = item[low].b;
            finalcart.cart2 = item[low].w;

            array[low] = array[high];
            item[low].b = item[high].b;
            item[low].w = item[high].w;

            array[high] = temp;
            item[low].b = finalcart.cart1;
            item[low].w = finalcart.cart2;

            low++;
            high--;
        }
    }

    return low;
}

void sort(element item[], int array[], int low, int high)
{
    int mid = knapsack(item, array, low, high);

    if (low < (mid - 1))
    {
       sort(item, array, low, mid - 1);
    }

    if (mid < high)
    {
       sort(item, array, mid, high);
    }
}

int main()
{
    int N;
    double W, cartb = 0, cartw = 0;

    cin >> N >> W;

    int array[N];
    element item[N];

    for(int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    for(int i = 0; i < N; i++)
    {
        cin >> item[i].w;
        item[i].b = array[i] * item[i].w;
    }

    sort(item, array, 0, N - 1);

    for(int i = 0; i < N - 1; i++)
    {
        if(item[i].w < W)
        {
            cartw = cartw + item[i].w;
            W = W - item[i].w;
            cartb = cartb + item[i].b;
        }

        else
        {
            cartw = cartw + W;
            cartb = cartb + (array[i] * W);
            i = N;
        }
    }

    cout << cartb; 

    return 0;
}