#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int memo[n + 1][sum + 1];
    // basecase
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
    
    // print
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
    vector<int> subset_sum;
    for (int i = 0; i <= sum; i++)
    {
        if (memo[n][i] == 1) subset_sum.push_back(i);
    }
    int min_subset_sum = INT_MAX;
    for (int val: subset_sum)
    {
        int s1 = val;
        int s2 = sum - s1;
        min_subset_sum = min(min_subset_sum, abs(s1 - s2));
    }
    cout << min_subset_sum;
    return 0;
}