#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int val[n];
    for (int i = 0; i < n; i++) cin >> val[i];

    int mem[n + 1][n + 1];
    // basecase
    for (int i = 0; i <= n; i++) mem[i][0] = 0; // weight   is 0 therefore no item can be taken
    for (int j = 0; j <= n; j++) mem[0][j] = 0; // item     is 0 therefore no item to take;
    // loop starts form 1, 1
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n ; j++)
        {
            if (i <= j)
            {
                mem[i][j] = max(val[i - 1] + mem[i][j - i], mem[i - 1][j]);
            }
            else
            {
                mem[i][j] = mem[i - 1][j];
            }
        }
    }
    cout << mem[n][n];
    return 0;
}

// 8
// 2 4 4 5 8 10 12 9