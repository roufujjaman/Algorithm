#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Write your code here
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n, c;
        cin >> n >> c;
        int weight[n];
        int val[n];
        int mem[n + 1][c + 1];
        for (int i = 0; i < n; i++) cin >> weight[i];
        for (int i = 0; i < n; i++) cin >> val[i];
        for (int i = 0; i <= n; i++) mem[i][0] = 0;
        for (int j = 0; j <= c; j++) mem[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (weight[i - 1] <= j)
                {
                    int with = val[i - 1] + mem[i - 1][j - weight[i - 1]];
                    int without = mem[i - 1][j];
                    mem[i][j] = max(with, without);
                }
                else
                {
                    mem[i][j] = mem[i - 1][j];
                }
                    
            }
        }
        cout << mem[n][c] << "\n";
    }
    return 0;
}

// Sample Input 0

// 2
// 4 7
// 2 3 4 5
// 4 7 6 5
// 4 17
// 10 1 6 9
// 6 10 10 8
// Sample Output 0

// 13
// 28
// Explanation 0

// In the first test case case, he can take 2nd and 3rd item which total weight is 3+4=7 and total value is 7+6=13 and its the maximum value possible.