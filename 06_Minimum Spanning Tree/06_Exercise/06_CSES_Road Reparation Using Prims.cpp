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
int dsu_find(vector<int> &parent, int node)
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
    vector<int> parent(1e5 + 1, -1);
    vector<int> parent_size(1e5 + 1, 1);
    long long int mst_length = 0;
    int edge_count = 0;
    for (Edge e: ed)
    {
        int leader_a = dsu_find(parent, e.u);
        int leader_b = dsu_find(parent, e.v);

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
    if (edge_count == n - 1) cout << mst_length << "\n";
    else cout << "IMPOSSIBLE";
    return 0;
}

// Input:

// 5 6
// 1 2 3
// 2 3 5
// 2 4 2
// 3 4 8
// 5 1 7
// 5 4 4
// Output:

// 14
