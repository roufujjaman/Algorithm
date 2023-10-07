#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n + 1], memo[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    memo[1] = 0;
    memo[2] = abs(arr[2] - arr[1]);
    for (int i = 3; i <= n; i++)
    {
        int left = abs(arr[i] - arr[i - 1]) + memo[i - 1];
        int right = abs(arr[i] - arr[i - 2]) + memo[i - 2];
        memo[i] = min(left, right);
    }
    cout << memo[n];
    return 0;
}