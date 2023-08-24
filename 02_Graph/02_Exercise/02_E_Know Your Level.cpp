#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
vector<int> shops;
void bfs(int s, int query)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        if(query == level[u]) shops.push_back(u);
        
        for (int v: adj[u])
        {
            if (visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
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
    bfs(0, query);
    if (shops.size() == 0) cout << -1 << "\n";
    else
    {
        sort(shops.begin(), shops.end());
        for (int shop: shops)
        {
            cout << shop << " ";
        }
    }
    return 0;
}