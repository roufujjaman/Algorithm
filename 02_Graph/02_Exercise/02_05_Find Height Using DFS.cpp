#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N];
bool visited[N];
int depth[N];
void dfs(int u)
{
    visited[u] = true;
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
    dfs(1);
    int query;
    cin >> query;
    cout << "Depth of " << query << " = " << depth[query];
    return 0;
}

// Sample Input
// Sample Output
// 7 
// 6
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 7
// Depth of 7 = 1
// 7 
// 6
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 4
// Depth of 4 = 2


