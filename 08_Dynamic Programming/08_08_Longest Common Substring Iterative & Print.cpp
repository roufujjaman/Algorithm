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
                mem[i][j] = mem[i - 1][j - 1] + 1;
            }
            else
            {
                mem[i][j] = 0;
            }
        }
    }
    int max = 0;
    int mi, mj;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (mem[i][j] > max)
            {
                max = mem[i][j];
                mi = i;
                mj = j;
            }
        }
    }
    string str;
    while (mi != 0 && m != 0)
    {
        if (a[mi - 1] == b[mj - 1])
        {
            str.push_back(a[mi -1]);
            mi--;
            mj--;
        }
        else
        {
            break;
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
