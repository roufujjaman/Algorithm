#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for (int v: adj[u])
        {
            if (visited[v] == true) continue;
            q.push(v);
            level[v] = level[u] + 1;
            visited[v] = true;
        }
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
        adj[v].push_back(u);
    }
    int query;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        for (int i = 0; i < N; i++)
        {
            level[i] = -1;
            visited[i] = false;
        }
        int s, d;
        cin >> s >> d;
        bfs(s);
        cout << level[d] << "\n";
    }
    return 0;
}