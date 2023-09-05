#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 1e9;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);
int visited[N];
int parent[N];
void dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;
    pq.push({s, 0});
    visited[s] = true;
    dist[s] = 0;
    parent[s] = -1;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();

        visited[u] = true;

        for (pair<int, int> vpair: g[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
                parent[v] = u;
            }
        }
    }

}
void print_path(int d)
{
    if (d == -1) return;
    print_path(parent[d]);
    cout << d << " > "; 
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
        g[v].push_back({u, w});
    }
    int source, destination;
    cin >> source >> destination;
    dijkstra(source);
    cout << dist[destination] << "\n";

    print_path(destination);  
    
    return 0;
}
