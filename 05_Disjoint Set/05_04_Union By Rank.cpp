#include<bits/stdc++.h>
using namespace std;
void dsu_set(int parent[], int parent_rank[], int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        parent_rank[i] = 1;
    }
}
int dsu_find(int parent[], int query_node)
{
    while (parent[query_node] != -1)
    {
        query_node = parent[query_node];
    }
    return query_node;
}
void dsu_union(int parent[], int parent_rank[], int a, int b)
{
    int leader_a = dsu_find(parent, a);
    int leader_b = dsu_find(parent, b);
    if (leader_a != leader_b)
    {
        if (parent_rank[leader_a] > parent_rank[leader_b])
        {
            parent[leader_b] = leader_a;
        }
        else if (parent_rank[leader_b] > parent_rank[leader_a])
        {
            parent[leader_a] = leader_b;
        }
        else // levels are equal
        {
            parent[leader_b] = leader_a;
            parent_rank[leader_a]++;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int parent[n];
    int parent_level[n];
    dsu_set(parent, parent_level, n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(parent, parent_level, a, b);
    }
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << "  ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << parent_level[i] << "  ";
    }
    return 0;
}


// 15 11
// 0 1
// 0 2
// 2 3
// 4 5
// 6 7
// 4 7
// 10 11
// 12 13
// 10 12
// 12 6
// 4 3