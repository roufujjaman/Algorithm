#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
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
    // Write your code here
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> nodes;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == true) continue;
        int count = dfs(i);
        if (count > 1) nodes.push_back(count);
    }
    sort(nodes.begin(), nodes.end());
    for (int i: nodes)
    {
        cout << i << " ";
    }
    return 0;
}