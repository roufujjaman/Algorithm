#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 1e9;
int n, m;
int dist[N][N];
void init_dist()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i != j) dist[i][j] = INF;
        }
    }
}
void print_matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF) cout << "X" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
void floyd_warshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    init_dist();
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    print_matrix();
    cout << "\n";
    floyd_warshall();
    print_matrix();
    return 0;
}
// 4
// 7
// 1 2 3
// 1 4 7
// 2 1 8
// 2 3 2
// 3 4 1
// 3 1 5
// 4 1 2