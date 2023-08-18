#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    // s t e p - 1
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        // s t e p - 2
        int u = q.front();
        q.pop(); 

        visited[u] = true;
        cout << "visiting - " << u << "\n";
        
        // s t e p - 3
        for(int v: adj[u])
        {
            if (visited[v] == true) continue;
            level[v] = level[u] + 1;
            q.push(v);
        }
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
    bfs(0);
    for (int u = 0; u < n; u++)
    {
        cout << "Node " << u << ": Level " << level[u] << "\n";
    }
    return 0;
}
