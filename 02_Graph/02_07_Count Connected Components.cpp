#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{   
    visited[u] = true;
    cout << u << " ";
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
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int connected_components = 0;
    for (int u = 0; u < n; u++)
    {
        if (visited[u] == true) continue;
        connected_components++;
        cout << "Component " << connected_components << ": ";
        dfs(u);
        cout << "\n";
    }
    cout << "Connected Components: " << connected_components;
    return 0;
}
