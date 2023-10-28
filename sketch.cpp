#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i <n ; i++)
    {
        cin >> arr[i];
    }
    int memo[n + 1][sum + 1];
    memo[0][0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        memo[0][i] = 0;
    }
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                memo[i][j] = (memo[i - 1][j - arr[i - 1]] + memo[i - 1][j]);// % mod;
            }
            else
            {
                memo[i][j] = memo[i - 1][j];// % mod;
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
    return 0;
}