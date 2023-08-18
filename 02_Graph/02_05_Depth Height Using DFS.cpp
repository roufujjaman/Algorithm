#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)
{
    visited[u] = true;
    for (int v: adj[u])
    {
        if (visited[v] == true) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        height[u] = max(height[v] + 1, height[u]); // when maximum depth is reached
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
    dfs(0);
    for (int u = 0; u < n; u++) // Node - {height, depth}
    {
        cout << "N[" << u << "]" << "\t- {" << height[u];
        cout << ", " << depth[u] << "}" << "\n";
    }
    return 0;
}
