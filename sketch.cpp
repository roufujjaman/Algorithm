#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool visited[100];
int cnt = 0;
int dfs(int u)
{
    visited[u] = true;
    int size = 1;
    for (int v: adj[u])
    {
        if (visited[v] == true) continue;
        size += dfs(v);
    }
    return size;
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
    for (int i = 0; i < 10; i++)
    {
        if (visited[i] == true) continue;
        cout << dfs(i) << " ";
    }
    return 0;
}