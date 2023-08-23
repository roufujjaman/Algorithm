#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N];
bool visited[N];
bool dfs(int u, int parent)
{
    visited[u] = true;
    bool is_cycle = false;
    for (int v: adj[u])
    {
        if (v == parent) continue;
        if (visited[v] == true)
        {
            return true;
        }
        is_cycle |= dfs(v, u);
    }
    return is_cycle;
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
    dfs(1, -1)? cout << "YES" : cout << "NO";
    return 0;
}
