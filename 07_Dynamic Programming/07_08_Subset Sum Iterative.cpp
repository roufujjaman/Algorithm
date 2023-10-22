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
    int s;
    cin >> s;
    bool memo[n + 1][s + 1];
    memo[0][0] = true;
    for (int i = 1; i <= s; i++)
    {
        memo[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
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
        for (int j = 0; j <= s; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
    memo[n][s]? cout << "YES" : cout << "NO";
    return 0;
}



// 4
// 1 2 4 6
// 7

// 4
// 1 3 4 6
// 7

