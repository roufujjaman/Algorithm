#include<bits/stdc++.h>
using namespace std;
void dsu_set(int parent[], int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
}
int dsu_find(int parent[], int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
int dsu_union(int parent[], int a, int b)
{
    a = dsu_find(parent, a);
    b = dsu_find(parent, b);
    if (a != b)
    {
        parent[b] = a;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int parent[n];
    dsu_set(parent, n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(parent, a, b);
    }


    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " ";
    }

    cout << "\n" << dsu_find(parent, 4) << " "; 
    cout << parent[4];
    return 0;
}