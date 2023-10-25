#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int memo[n + 1][target + 1];

    // basecase
    for (int i = 0; i <= target; i++)
    {
        if (i == 0) memo[0][i] = 1;
        else memo[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (arr[i - 1] <= j)
            {
                int with = memo[i - 1][j - arr[i - 1]];
                int without = memo[i - 1][j];
                memo[i][j] = with + without;
            }
            else
            {
                memo[i][j] = memo[i - 1][j];
            }
        }
    }

    // print
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
    cout << memo[n][target];
    return 0;
}