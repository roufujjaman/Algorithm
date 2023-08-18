#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N];
int visisted[N];
void dfs(int u)
{
    visisted[u] = true;
    for (int v: adj[u])
    {
        if (visisted[v] == true) continue;
        dfs(v);
    }
    cout << u << " ";
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
    dfs(1);
    return 0;
}
