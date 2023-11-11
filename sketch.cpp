#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    int n = s1.size();
    int mem[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        mem[i][0] = 0;
        mem[0][i] = 0;
    } 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
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
    cout << mem[n][n] << "\n";
    int ci = n, cj = n;
    string str;
    while (ci != 0 && cj != 0)
    {
        if (s1[ci - 1] == s2[cj - 1])
        {
            str.push_back(s1[ci - 1]);
            ci--;
            cj--;
        }
        else
        {
            if (mem[ci - 1][cj] > mem[ci][cj - 1])
            {
                ci--;
            }
            else
            {
                cj--;
            }
        }
    }
    reverse(str.begin(), str.end());
    cout << str;
}


