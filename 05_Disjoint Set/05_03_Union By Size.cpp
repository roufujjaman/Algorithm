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
    a = dsu_find(parent, a);
    b = dsu_find(parent, b);
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
    int parent[n];
    int parent_size[n];
    dsu_set(parent, parent_size, n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(parent, parent_size, a, b);
    }
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << "  ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << parent_size[i] << "  ";
    }
    return 0;
}
