#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 1e9;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);
int visited[N];
void dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;
    dist[s] = 0;
    visited[s] = true; // true or 1;
    pq.push({s, dist[s]});

    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();

        visited[u] = true;

        for (pair<int, int> vpair: g[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});

            }
        }
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
        g[u].push_back({v, w});
    }
    int source, destination;
    cin >> source >> destination;
    dijkstra(source);
    cout << dist[destination];
    return 0;
}
