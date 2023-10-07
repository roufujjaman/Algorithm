#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
int memo[N];
void init_memo(int n)
{
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }
}
int jump(int arr[], int n)
{
    if (n == 1) return 0;
    else if (memo[n] != -1) return memo[n];
    else if (n == 2)
    {   
        return memo[n] = abs(arr[n] - arr[n - 1]); 
    }
    else
    {
        int left = abs(arr[n] - arr[n - 1]) + jump(arr, n - 1);
        int right = abs(arr[n] - arr[n - 2]) + jump(arr, n - 2);
        return memo[n] = min(left, right);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    init_memo(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << jump(arr, n);
    return 0;
}