#include<bits/stdc++.h>
using namespace std;
long long int fn(int i, long long int arr[], long long int memo[])
{
	if (i < 0) return 0;
    if (i == 0) return arr[0];
    if (i == 1) return max(arr[0], arr[1]);
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
    for (int i = 0; i < count; i++)
    {
        int size;
        cin >> size;
        long long int memo[size + 2];
        for (int j = 0; j < size; j++)
        {
            memo[j] = -1;
            cin >> arr[j];
        }
        cout << "Case " << i + 1 << ": " << fn(size - 1, arr, memo) << "\n";
    }
    return 0;
}