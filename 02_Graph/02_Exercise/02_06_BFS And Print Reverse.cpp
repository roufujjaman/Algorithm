#include<bits/stdc++.h>
using namespace std;
vector<int> adj[20];
bool visited[20];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    stack<int> stk;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        stk.push(u);

        for (int v: adj[u])
        {
            if (visited[v] == true) continue;
            visited[v] = true;
            q.push(v);
        }
    }
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
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
    bfs(1);
    return 0;
}
