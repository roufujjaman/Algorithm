#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 1e9;
int n, m;
vector<pair<int, int>> g[N];
int dist[N];

void bellman_ford(int s)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;

        dist[s] = 0;

        
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    return 0;
}
