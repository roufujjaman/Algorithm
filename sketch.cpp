#include<bits/stdc++.h>
using namespace std;
const int N = 20;
vector<int> adj[N];
bool visited[N];
int level[N];
void dfs(int u)
{
    visited[u] = true;
    // level[u] = 1;
    for (int v: adj[u])
    {
        if (visited[v] == true) continue;
        level[v] = level[u] + 1;
        dfs(v);
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
    int query;
    cin >> query;
    cout << "Level of " << query << " = " << level[query];
    return 0;
}