#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int can_go = 0;
void dfs(int u)
{
    visited[u] = true;
    
    for (int v: adj[u])
    {
        if (visited[v] == true) continue;
        can_go++;
        dfs(v);
    }
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
    }
    int query;
    cin >> query;
    dfs(query);
    cout << can_go << "\n";
    return 0;
}