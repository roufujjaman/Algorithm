#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int num;
        int sum = 0;
        cin >> num;
        int nums[num];
        for (int i = 0; i < num; i++)
        {
            cin >> nums[i];
            sum += nums[i];
        }
        if (sum % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }
        int target = sum / 2;
        int mem[num + 1][target + 1];
        mem[0][0] = 1;
        for (int j = 1; j <= target; j++) mem[0][j] = 0;
        for (int i = 1; i <= num; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (nums[i - 1] <= j)
                {
                    mem[i][j] = mem[i - 1][j - nums[i - 1]] || mem[i - 1][j];
                }
                else
                {
                    mem[i][j] = mem[i - 1][j];
                }
            }
        }
        mem[num][target]? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}

// Sample Input 0

// 3
// 5
// 1 2 3 4 5
// 4
// 2 3 4 5
// 5
// 1 2 3 8 12
// Sample Output 0

// NO
// YES
// YES