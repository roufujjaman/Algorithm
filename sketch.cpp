#include<bits/stdc++.h>
using namespace std;
const int N = 15;
vector<int> adj[N];
bool visited[N];
void bfs(int u)
{
    if(adj[u].empty()) return;
    visited[u] = true;
    cout << u << " | ";
    for (int v: adj[u])
    {
        if (visited[v] == true) continue;
        bfs(v);
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
    for (int i = 0; i < N; i++)
    {
        cout << i << " | ";
        for (int j: adj[i])
        {
            cout << j << "  ";
        }
        cout << "\n";
    }
    for (int i = 0; i < N; i++)
    {
        if(visited[i] == true) continue;
        bfs(i);
        cout << "\n";
    }
    return 0;
}