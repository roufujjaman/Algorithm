#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, w;
    cin >> n >> w;
    int val[n], weight[n];
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> weight[i];
    
    int mem[n + 1][w + 1];
    // basecase
    for (int i = 0; i <= n; i++) mem[i][0] = 0; // weight   is 0 therefore no item can be taken
    for (int j = 0; j <= w; j++) mem[0][j] = 0; // item     is 0 therefore no item to take
    // loop starts from 1 & 1
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (weight[i - 1] <= j)
            {
                mem[i][j] = max(val[i - 1] + mem[i][j - weight[i - 1]], mem[i - 1][j]);
            }
            else
            {
                mem[i][j] = mem[i - 1][j];
            }
        }
    }
    cout << mem[n][w];
    return 0;
}

// 4 6
// 5 3 2 4
// 4 1 3 2
