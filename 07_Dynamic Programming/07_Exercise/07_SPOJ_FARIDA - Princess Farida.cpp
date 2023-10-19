#include<bits/stdc++.h>
using namespace std;
void init_memo(int n, long long int arr[])
{
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
}
int fn(int i, long long int arr[], long long int memo[])
{
    if (i < 0) return 0;
    if (memo[i] != -1) return memo[i];
    long long int withCurrent = fn(i - 2, arr, memo) + arr[i];
    long long int withoutCurrent = fn(i - 1, arr, memo);
    return memo[i] = max(withCurrent, withoutCurrent);
}
int main()
{
    int count;
    cin >> count;
    long long int arr[10002];
    long long int memo[10002];
    for (int i = 0; i < count; i++)
    {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            cin >> arr[j];
        }
        init_memo(size, memo);
        cout << "Case " << i + 1 << ": " << fn(size - 1, arr, memo) << "\n";
    }
    return 0;
}
