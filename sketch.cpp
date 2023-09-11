#include<bits/stdc++.h>
using namespace std;
const int N = 100;
const int INF = 1e9;
vector<pair<int, int>> adj[N];
vector<bool> visited(N);
vector<int> dist(N, INF);
void dijkstra(int source)
{
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (pair<int, int> vpair: adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v] == true) continue; 
            
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    int n, m, source;
    cin >> n >> m >> source;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dijkstra(source);
    
    cout << "Source: " << source << "\n"; 
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INF) continue;
        cout << "Distance if node " << i << ": " << dist[i] << "\n";
    }
    return 0;
}

// 8
// 11
// 3 10 5
// 3 5 3
// 3 8 2
// 3 4 1
// 5 6 6
// 5 7 2
// 10 6 7
// 6 7 1
// 7 9 3
// 9 4 10
// 8 7 11
// 3

