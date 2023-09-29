#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> parent(N, -1);
vector<int> parent_size(N, 1);
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
int componenet_max = 0;
void dsu_union(int a, int b)
{
    int leader_a = dsu_find(a);
    int leader_b = dsu_find(b);
    if (leader_a != leader_b)
    {
        if (parent_size[leader_a] > parent_size[leader_b])
        {
            parent[leader_b] = leader_a;
            parent_size[leader_a] += parent_size[leader_b];
            componenet_max = max(componenet_max, parent_size[leader_a]);
        }
        else
        {
            parent[leader_a] = leader_b;
            parent_size[leader_b] += parent_size[leader_a]; 
            componenet_max = max(componenet_max, parent_size[leader_b]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int components = n;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int leader_a = dsu_find(a);
        int leader_b = dsu_find(b);
        if (leader_a != leader_b)
        {
            dsu_union(leader_a, leader_b);
            components--;
        }
        cout << components << " " << componenet_max << "\n";
    }
    return 0;
}

// 5 3
// 1 2
// 1 3
// 4 5