#include<bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)
{
    visited[u] = true;
    printf("visiting - %d\n", u);
    for (int v: adj[u])
    {
        if (visited[v] == true) continue;
        depth[v] = depth[u] + 1;
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
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        printf("depth N[%d] - %d\n", i, depth[i]);
    }
    return 0;
}
