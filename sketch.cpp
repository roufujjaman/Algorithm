#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
int n, m;
int fn(int si, int sj)
{
    if (si == n && sj == m) return arr[si][sj];
    if (si > n || sj > m) return -1000000;
    int mvi = arr[si][sj] + fn(si + 1, sj);
    int mvj = arr[si][sj] + fn(si, sj + 1);
    return max(mvi, mvj);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << fn(1, 1) << "\n";
    return 0;
}