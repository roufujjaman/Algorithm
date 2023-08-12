#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int adjmat[N][N];
int main()
{
    int n, m, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjmat[u][v] = w;
        adjmat[v][u] = w;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjmat[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
