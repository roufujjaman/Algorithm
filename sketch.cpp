#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << level[u] << "(" << u << "  ";

        for (int v: adj[u])
        {
            if (visited[v] == true) continue;
            visited[v] = true;
            level[v] = level[u] + 1;
            q.push(v);
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
    for (int u = 0; u < n; u++)
    {
        cout << "N" << u << " - ";
        for (int v: adj[u])
        {
            cout << v << " ";
        }
        cout << "\n";
    }
    int connected_component = 0;
    for (int i = 0; i < n; i++)
    {
        if(visited[i] == true) continue;
        connected_component++;
        cout << connected_component << "\n";
        bfs(i);
        cout << "\n";
    }
    return 0;
}