#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u, v, w;
        Edge (int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
bool cmp (Edge a, Edge b)
{
    return a.w < b.w;
}
const int N = 1e5 + 1;
int parent[N];
int parent_size[N];
void dsu_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        parent_size[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    a = dsu_find(a);
    b = dsu_find(b);
    if (a != b)
    {
        if (parent_size[a] > parent_size[b])
        {
            parent[b] = a;
            parent_size[a] += parent_size[b];
            // parent_size[b] = 0;
        }
        else
        {
            parent[a] = b;
            parent_size[b] += parent_size[a];
            // parent_size[a] = 0;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> ed;
    vector<Edge> mst_edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ed.push_back({u, v, w});
    }
    sort(ed.begin(), ed.end(), cmp);
    dsu_set(n);
    for (Edge e: ed)
    {
        int u = e.u;
        int v = e.v;
        int leader_a = dsu_find(u);
        int leader_b = dsu_find(v);
        if (leader_a == leader_b) continue;
        mst_edges.push_back(e);
        dsu_union(u, v);
    }
    for (Edge e: mst_edges)
    {
        cout << e.u << " " << e.v << " " << e.w << "\n";
    }
    return 0;
}
// 5 6
// 1 2 3
// 1 5 7
// 2 3 5
// 3 4 8
// 4 5 4
// 2 4 2