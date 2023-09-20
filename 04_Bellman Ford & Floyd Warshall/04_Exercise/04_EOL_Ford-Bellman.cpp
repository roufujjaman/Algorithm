#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u;
        int v;
        int w;
        Edge (int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> ed;
    for (int i = 0; i < m; i++)
    {
        int u, v , w;
        cin >> u >> v >> w;
        Edge input_val(u, v, w);
        ed.push_back(input_val);
    }
    int INF = 30000;
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (Edge e: ed)
        {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
      cout << dist[i] << ' ';
    }
    return 0;
}