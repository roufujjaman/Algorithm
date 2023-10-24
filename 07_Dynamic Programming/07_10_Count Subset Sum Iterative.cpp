#include<bits/stdc++.h>
using namespace std;
int fn(int n, int target, int arr[])
{
    if (n == 0)
    {
        if (target == 0) return 1;
        else return 0;
    }
    if (arr[n - 1] <= target)
    {
        int with = fn(n - 1, target - arr[n - 1], arr);
        int without = fn(n - 1, target, arr);
        return with + without;
    }
    return fn(n- 1, target, arr);
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
    cout << fn(n, target, arr);
    return 0;
}