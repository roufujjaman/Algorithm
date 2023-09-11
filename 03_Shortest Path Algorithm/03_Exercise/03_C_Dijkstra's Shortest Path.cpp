vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<pair<int, int>> g[vertices];
    for (int i = 0; i < edges; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    const int INF = 1e5;
    vector<int> dist(vertices, INF);
    vector<bool> visited(vertices, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (pair<int, int> vpair: g[u])
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
    return dist;
}