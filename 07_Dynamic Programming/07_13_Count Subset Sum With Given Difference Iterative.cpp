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
    int diff;
    cin >> diff;
    if ((sum - diff) % 2 == 0)
    {
        int target = (sum - diff) / 2;
        int mem[n + 1][target + 1];
        mem[0][0] = 1;
        for (int j = 1; j <= target; j++) mem[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
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
        cout << mem[n][target];
    }
    else
    {
        cout << 0;
    }
    return 0;
}