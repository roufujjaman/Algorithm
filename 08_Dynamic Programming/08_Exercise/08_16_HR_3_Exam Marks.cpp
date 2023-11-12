#include <bits/stdc++.h>
const int N = 1e9+7;
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int points[n];
        for (int i = 0; i < n; i++) cin >> points[i];
        m = 1000 - m;
        if (m == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        int mem[n + 1][m + 1];
        mem[0][0] = 1;
        for (int i = 1; i <= m; i++) mem[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (points[i - 1] <= j)
                {
                    mem[i][j] = (mem[i][j - points[i - 1]] + mem[i - 1][j]) % N;
                }
                else
                {
                    mem[i][j] = mem[i - 1][j] % N;
                }
            }
        }
        cout << mem[n][m] << "\n";
    }
    return 0;
}


// Sample Input 0

// 5
// 5 1000
// 1 2 3 4 5
// 5 999
// 2 3 4 5 6
// 2 900
// 30 40
// 3 904
// 2 6 5
// 2 904
// 2 5
// Sample Output 0

// 1
// 0
// 1
// 92
// 10