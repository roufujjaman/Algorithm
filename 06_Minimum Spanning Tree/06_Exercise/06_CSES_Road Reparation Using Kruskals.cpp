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
int dsu_find(vector<int> parent, vector<int> parent_size, int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> ed(m, {0, 0, 0});
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ed[i] = {u, v, w};
    }
    sort(ed.begin(), ed.end(), cmp);
    vector<int> parent(n + 1, -1);
    vector<int> parent_size(n + 1, -1);
    long long int mst_length = 0;
    int edge_count = 0;
    for (Edge e: ed)
    {
        if (mst_length == n - 1) break;
        int leader_a = dsu_find(parent, parent_size, e.u);
        int leader_b = dsu_find(parent, parent_size, e.v);
        if (leader_a != leader_b)
        {
            mst_length += (long long int)e.w;
            edge_count++;
            if (parent_size[leader_a] > parent_size[leader_b])
            {
                parent[leader_b] = leader_a;
                parent_size[leader_a] += parent_size[leader_b];
            }
            else
            {
                parent[leader_a] = leader_b;
                parent_size[leader_b] += parent_size[leader_a]; 
            }
        }
    }
    if (edge_count == n - 1) cout << mst_length;
    else cout << "IMPOSSIBLE";
    return 0;
}
