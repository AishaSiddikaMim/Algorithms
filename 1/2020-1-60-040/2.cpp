#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int mid, low = 0, high = num;
    double ans;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if ((mid * mid) == num)
        {
            ans = mid;
            break;
        }

        else if((mid * mid) < num)
        {
            low = mid + 1;
            ans = mid;
        }

        else if((mid * mid) > num)
        {
            high = mid - 1;
        }

    }

    double add = 0.1;

    for(int i = 0; i < 3; i++) // 3 places after decimal
    {
        while((ans * ans) <= num)
        {
            ans = ans + add;
        }

        ans = ans - add;
        add = add / 10;
    }

    cout << ans << setprecision(3) << endl;
}