#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    
    int n, m;
    n = a.size();
    m = b.size();
    
    int mem[n + 1][m + 1];
    for (int i = 0; i <= n; i++) mem[i][0] = 0;
    for (int j = 0; j <= m; j++) mem[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                mem[i][j] = 1 + mem[i - 1][j - 1];
            }
            else
            {
                mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << mem[i][j] << " ";
        }
        cout << "\n";
    }
    int i = n, j = m;
    string str;
    while (i != 0 && j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            str.push_back(a[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (mem[i][j - 1] > mem[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(str.begin(), str.end());
    cout << str;
    return 0;
}

// abcdfgr
// acfdgr

// rotomono
// rofomono