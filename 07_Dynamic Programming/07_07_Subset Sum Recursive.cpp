#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> memo(N, -1);
bool fn(int n, int s, int arr[])
{
    if (n == 0)
    {
        if (s == 0) return true;
        else return false;
    }
    if (memo[n - 1] != -1) return memo[n];
    if (arr[n - 1] <= s)
    {
        bool withCurrent = fn(n - 1, s - arr[n - 1], arr);
        bool withoutCurrent = fn(n - 1, s, arr);
        return memo[n - 1] = withCurrent || withoutCurrent;
    }
    else 
    {
        return memo[n - 1] = fn(n - 1, s, arr);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[N];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s;
    cin >> s;
    (fn(n, s, arr))? cout << "YES" : cout << "NO";
    return 0;
}



// 4
// 1 2 4 6
// 7