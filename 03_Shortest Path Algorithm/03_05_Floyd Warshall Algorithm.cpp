#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 1e9;
int dist[N][N];
int n, m;
void dist_initialize()
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
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dist[i][j] << "  ";
        }
        cout << "\n";    
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    print_matrix();
    return 0;
}