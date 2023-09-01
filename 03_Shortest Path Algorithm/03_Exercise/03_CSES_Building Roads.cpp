#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    visited[u] = true;
    for (int v: adj[u])
    {
        if (visited[v] == true) continue;
        dfs(v);
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
    vector<int> head;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true) continue;
        head.push_back(i);
        dfs(i);
    }
    cout << head.size() - 1 << "\n";
    for (size_t i = 1; i < head.size(); i++)
    {
        cout << head[i - 1] << " " << head[i] << "\n";
    }
    return 0;
}
