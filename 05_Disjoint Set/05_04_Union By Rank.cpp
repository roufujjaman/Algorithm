#include<bits/stdc++.h>
using namespace std;
void dsu_set(int parent[], int parent_rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        parent_rank = 1;
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
            parent[b] = a;
            
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int parent[n];
    int parent_rank[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

    }

    return 0;
}
