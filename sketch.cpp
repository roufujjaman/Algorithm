#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int val[n];
    for (int i = 0; i < n; i++) cin >> val[i];
    int s;
    cin >> s;
    int mem[n + 1][s + 1];
    mem[0][0] = 1;
    for (int j = 1; j <= s; j++) mem[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (val[i - 1] <= j)
            {
                mem[i][j] = mem[i][j - val[i - 1]] + mem[i - 1][j];
            }
            else
            {
                mem[i][j] = mem[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << mem[i][j] << " ";
        }
        cout << "\n";
    }

    cout << mem[n][s];
    return 0;
}

// 3
// 1 2 3
// 5

