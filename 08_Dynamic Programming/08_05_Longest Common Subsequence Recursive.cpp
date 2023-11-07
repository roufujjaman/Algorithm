#include<bits/stdc++.h>
using namespace std;
int mem[1005][1005];
int fn(int n, int m, string a, string b)
{
    // basecase
    if (n == 0 || m == 0) return 0;
    // memoization
    if (mem[n][m] != -1) return mem[n][m];
    if (a[n - 1] == b[m - 1])
    {
        return mem[n][m] = 1 + fn(n - 1, m - 1, a, b);
    }
    else
    {
        return mem[n][m] = max(fn(n - 1, m, a, b), fn(n, m - 1, a, b));
    }
}
int main()
{
    string a, b;
    cin >> a >> b;
    
    int n, m;
    n = a.size();
    m = b.size();
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            mem[i][j] = -1;
        }
    }
 
    cout << fn(a.size(), b.size(), a, b);
    return 0;
}

// abcdfgr
// acfdgr