#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Write your code here
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a;
        b = a;
        reverse(b.begin(), b.end());
        int n = a.size();
        int mem[n + 1][n + 1];
        for (int i = 0; i <= n; i++) mem[i][0] = 0;
        for (int j = 0; j <= n; j++) mem[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
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
        cout << n - mem[n][n] << "\n";
    }
    return 0;
}


// Sample Input 0

// 5
// madam
// mcadam
// madcam
// mcaedam
// macdarm
// Sample Output 0

// 0
// 1
// 1
// 2
// 2
