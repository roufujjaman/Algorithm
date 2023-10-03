#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 1e9;
int n, m;
vector<pair<int, int>> g[N];
int dist[N];

void bellman_ford(int s)
{
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INF;
    }
    
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) // node - 1;
    {
        for (int u = 0; u <= n; u++) // going  to all nodes to access all the edges using adjucency list
        {
            for (pair<int, int> vpair: g[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if (dist[u] != INF && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    bellman_ford(1);
    for (int i = 0; i <= n; i++)
    {
        cout << "dist of [" << i << "] - " << dist[i] << "\n";
    }
    return 0;
}


// 7
// 10
// 1 2 6
// 1 3 5
// 1 4 5
// 2 5 -1
// 3 2 -2
// 3 5 1
// 4 3 -2
// 4 6 -1
// 5 7 3
// 5 7 3
