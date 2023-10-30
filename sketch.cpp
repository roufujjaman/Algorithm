#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int target;
    cin >> target;
    
    if ((sum - target) % 2 == 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    
    int t = (sum - target) / 2;
    int mem[n + 1][t + 1];
    mem[0][0] = 1;
    for (int j = 1; j <= t; j++) mem[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            if (arr[i - 1] <= j)
            {
                mem[i][j] = mem[i - 1][j - arr[i - 1]] + mem[i - 1][j];
            }
            else
            {
                mem[i][j] = mem[i- 1][j];
            }
        }
    }
    cout << mem[n][t] << "\n";
    return 0;
}



// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

