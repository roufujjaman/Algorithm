#include<bits/stdc++.h>
using namespace std;
void dsu_set(int parent[], int parent_size[], int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        parent_size[i] = 1;
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
void dsu_union(int parent[], int parent_size[], int a, int b)
{
    a = dsu_find(a);
    b = dsu_find(b);
    if (a != b)
    {
        if (parent_size[a] > parent_size[b])
        {
            parent[b] = a;
            parent_size[a]
        }
        else
        {

        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int parent[n];
    int parent_size[n];

    return 0;
}
