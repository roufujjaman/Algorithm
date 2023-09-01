#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N];
vector<int> dist(N, -1);
vector<int> visited(N);
vector<int> parent(N);
void bfs(int source)
{
    queue<int> q;
    q.push(source);

    visited[source] = true;
    dist[source] = 1;
    parent[source] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v: adj[u])
        {
            if(visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            dist[v] = dist[u] + 1;
            parent[v] = u;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    if (dist[n] == -1) cout << "IMPOSSIBLE";
    else
    {
        cout << dist[n] << "\n";
        int current = n;
        vector<int> path;
        while (current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());
        for (int n: path)
        {
            cout << n << " ";
        }
    }
    return 0;
}
