#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i <n ; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int target;
    cin >> target;
    bool memo[n + 1][sum + 1];
    memo[0][0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        memo[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                memo[i][j] = memo[i - 1][j - arr[i - 1]] || memo[i - 1][j];
            }
            else
            {
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
    int count = 0;
    for (int i = 0; i <= sum; i++)
    {
        if (memo[n][i] == 1) cout << i << " ";
        if (target == (sum - i) - i || target == (sum - i) + i) count ++;
    }
    cout << "\n" << count;
    return 0;
}