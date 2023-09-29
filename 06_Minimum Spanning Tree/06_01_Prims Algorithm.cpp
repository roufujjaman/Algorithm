#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u, v, w;
        Edge(int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
class cmp
{
    public:
        bool operator()(Edge a, Edge b)
        {
            return b.w < a.w;
        }
};
const int N = 1e3;
vector<pair<int, int>> adj[N];
int visited[N];
void prims(int source)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push({source, source, 0});
    vector<Edge> edges;
    while (!pq.empty())
    {
        int u = pq.top().u;
        int v = pq.top().v;
        int w = pq.top().w;
        pq.pop();

        if (visited[v] == true) continue;

        edges.push_back({u, v, w});
        visited[v] = true;
        
        for (pair<int, int> vpair: adj[v])
        {
            int nv = vpair.first;
            int nw = vpair.second;
            if (visited[nv] == false)
            {
                pq.push({v, nv, nw});
            }
        }
    }
    edges.erase(edges.begin()); // removes first value;
    for (Edge val: edges)
    {
        cout << val.u << " " << val.v << " " << val.w << "\n";
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    prims(1);
    return 0;
}

// 8 11
// 1 5 2
// 1 2 4
// 1 4 10
// 5 4 5
// 2 4 8
// 2 3 18
// 3 4 11
// 4 8 9
// 4 7 11
// 7 6 1
// 8 6 2
