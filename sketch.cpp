#include<bits/stdc++.h>
using namespace std;

// typedef pair<int, int> pii;

const int N = 100;
const int INF = 1e9+11;

// vector<pii> adj[N];

vector<pair<int, int>> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);
void dijkstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (pair<int, int> vpair: adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v] == true) continue;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    int u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int source;
    cin >> source;
    dijkstra(source);
    for (int i = 0; i <= n; i++)
    {
        cout << "Distance of N[" << i << "]: ";
        cout << dist[i] << "\n";
    }
    return 0;
}