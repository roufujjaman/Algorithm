#include<bits/stdc++.h>
using namespace std;
int sum = 0;
int jump(int arr[], int n)
{
    if (n == 1) return 0;
    else if (n == 2) return abs(arr[n] - arr[n -1]);
    else
    {
        int left = abs(arr[n] - arr[n - 1]) + jump(arr, n - 1);
        int right = abs(arr[n] - arr[n - 2]) + jump(arr, n - 2);
        return min(left, right);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << jump(arr, n);
    return 0;
}