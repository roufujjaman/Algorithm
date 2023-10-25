#include<bits/stdc++.h>
using namespace std;
int memo[100][100];
// initialize the memoization array
void init_memo(int n, int target)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            memo[i][j] = -1;
        }
    }
}
int fn(int n, int target, int arr[])
{
    // basecase
    if (n == 0)
    {
        if (target == 0) return 1;
        else return 0;
    }
    
    // check if memoized
    if (memo[n][target] != -1) return memo[n][target];
    
    // arr[] contains set elements starts from 0
    if (arr[n - 1] <= target)
    {
        int with = fn(n - 1, target - arr[n - 1], arr); // with current element
        int without = fn(n - 1, target, arr);           // without current element
        return memo[n][target] = with + without;
    }
    return memo[n][target] =  fn(n - 1, target, arr); // without current element
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int memo[n + 1][target + 1];
    init_memo(n, target);
    cout << fn(n, target, arr) << "\n";
    return 0;
}



// 6
// 1 2 3 4 5 6
// 7