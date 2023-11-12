#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        w = 1000 - w;
        int points[n];
        for (int i = 0; i < n; i++) cin >> points[i];
        
        if (w == 0)
        {
            cout << "YES\n";
            continue;
        }
        int mem[n + 1][w + 1];
        for (int i = 0; i <= n; i++) mem[i][0] = 0;
        for (int j = 0; j <= w; j++) mem[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (points[i - 1] <= j)
                {
                    mem[i][j] = max(points[i - 1] + mem[i][j - points[i - 1]], mem[i - 1][j]);
                }
                else
                {
                    mem[i][j] = mem[i - 1][j];
                }
            }
        }
        if (mem[n][w] == w) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}



// Sample Input 0

// 3
// 5 1000
// 1 2 3 4 5
// 5 999
// 2 3 4 5 6
// 2 900
// 30 40
// Sample Output 0

// YES
// NO
// YES