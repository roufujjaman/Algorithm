#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    bool memo[n + 1][sum + 1];
    // basecase
    memo[0][0] = true;
    for (int i = 1; i <= sum; i++)
    {
        memo[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                bool with = memo[i - 1][j - arr[i - 1]];
                bool without = memo[i - 1][j];
                memo[i][j] = with || without;
            }
            else
            {
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
    int target;
    cin >> target;
    bool found = false;
    for (int i = 0; i <= sum; i++)
    {
        if (memo[n][i] == 1)
        {
            if (target == (sum - i) - i)
            {
                cout << target << " == " << sum - i << " - " << i << "\n";
                found = true;
                break;
            }
        }
    }
    if (found) cout << "true";
    else cout << "false";
    return 0;
}