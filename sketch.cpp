#include<bits/stdc++.h>
using namespace std;
const int N = 15;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v: adj[u])
        {
            if (visited[v] == true) continue;
            visited[v] = true;
            q.push(v);
            
            level[v] = level[u] + 1; // to find the distance     <<<<<<
            parent[v] = u;  // to find the path     <<<<<<
        }        
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source, destination;
    cin >> source >> destination;
    bfs(source);

    vector<int> path;
    int current = destination;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    cout << "Distance : " << level[destination] << "\n";
    cout << "Path : ";
    for (int p: path)
    {
        cout << p << " ";
    }
    return 0;
}