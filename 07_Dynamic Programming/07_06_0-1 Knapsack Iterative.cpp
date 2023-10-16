#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count, container;
    cin >> count >> container;
    int weight[count + 1];
    int val[count + 1];
    for (int i = 1; i <= count; i++)
    {
        cin >> weight[i];
        cin >> val[i];
    }
    int dp[count + 1][container + 1];
    for (int i = 0; i <= count; i++)
    {
        for (int  j = 0; j <= container; j++)
        {
            // basecase kinda
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= count; i++)
    {
        for (int j = 1; j <= container; j++)
        {
            if (weight[i] <= j)
            {
                int withCurrent = val[i] + dp[i - 1][j - weight[i]];
                int withoutCurrent = dp[i - 1][j];
                dp[i][j] = max(withCurrent, withoutCurrent);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[count][container];
    return 0;
}

// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U

// 6 15
// 6 5
// 5 6
// 6 4
// 6 6
// 3 5
// 7 2