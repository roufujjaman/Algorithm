#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int mem[n + 1][m + 1];
    for (int i = 0; i <= n; i++) mem[i][0] = 0;
    for (int j = 0; j <= m; j++) mem[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                mem[i][j] = 1 + mem[i - 1][j - 1];
            }
            else
            {
                mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
            }
        }
    }
    cout << (n + m) - mem[n][m];
    return 0;
}

// COMMONALL
// CONALL
