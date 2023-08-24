#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N];
bool visited[N];
bool dfs(int u, int component_id, vector<int> component[])
{
    visited[u] = true;
    component[component_id].push_back(u);
    for (int v: adj[u])
    {
        if (visited[v] == true) continue;
        dfs(v, component_id, component);
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
    int c_component = 0;
    vector<int> component[5];
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true) continue;
        c_component++;
        dfs(i, c_component, component);
    }
    cout << c_component << "\n";
    for (int i = 1; i <= c_component; i++)
    {
        cout << "Component " << i << " : ";
        for (int item: component[i])
        {
            cout << item << " ";
        }
        cout << "\n";
    }
    return 0;
}