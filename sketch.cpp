#include<bits/stdc++.h>
using namespace std;
const int N = 500;
const int INF = 1e9 + 11;
vector<int> adj[N];
vector<bool> visited(N);
vector<int> dist(N, INF);
void dijkstra(int source)
{
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0, source});

}
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source, destination;
    cin >> source >> destination; 
    dijkstra(source);
    return 0;
}