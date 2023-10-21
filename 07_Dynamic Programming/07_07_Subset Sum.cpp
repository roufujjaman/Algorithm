#include<bits/stdc++.h>
using namespace std;
int steps = 0;
bool fn(int n, int s, int arr[])
{
    steps++;
    cout << n << " " << s << '\n';
    if (n < 0)
    {
        if (s == 0) return true;
        else return false;
    }
    if (arr[n] <= s)
    {
        bool withCurrent = fn(n - 1, s - arr[n], arr);
        bool withoutCurrent = fn(n - 1, s, arr);
        return withCurrent || withoutCurrent;
    }
    else 
    {
        return fn(n - 1, s, arr);
    }
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
    int s;
    cin >> s;
    (fn(n - 1, s, arr))? cout << "YES" : cout << "NO";
    cout << "\n" << steps;
    return 0;
}



// 4
// 1 2 4 6
// 7