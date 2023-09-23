#include<bits/stdc++.h>
using namespace std;
int parent[1000];
void dsu_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
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
        parent[b] = a;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    dsu_set(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << i << " | ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " | ";
    }
    cout << "\n" << dsu_find(4);
    return 0;
}