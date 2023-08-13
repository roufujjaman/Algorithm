#include<bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    visited[u] = true;
    printf("visiting - %d\n", u);
    for (int v: adj[u])
    {
        if (visited[v] == true) continue;
        dfs(v);
    }
}
int main()
{
    int n, m; // n - number of nodes, m - number of edges
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        printf("N[%d] - ", i);
        for (int v: adj[i])
        {
            printf("%d ", v);
        }
        cout << '\n';
    }
    dfs(0);
    return 0;
}

// 9
// 10
// 0 1
// 1 8
// 8 6
// 6 7
// 6 5
// 5 3
// 5 4
// 3 2
// 4 2
// 2 0
