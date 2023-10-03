#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int parent[N];
int parent_level[N];
int edge_count = 0;
void dsu_set(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
        parent_level[i] = 1;
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
    int leader_a = dsu_find(a);
    int leader_b = dsu_find(b);
    if (leader_a == leader_b) edge_count++;
    if (leader_a != leader_b)
    {
        if (parent_level[leader_a] < parent_level[leader_b])
        {
            parent[leader_a] = leader_b;
        }
        else if (parent_level[leader_b] < parent_level[leader_a])
        {
            parent[leader_b] = leader_a;
        }
        else
        {
            parent[leader_b] = leader_a;
            parent_level[leader_a]++;
        }
    }
}
int main()
{
    // Write your code here
    int n, m;
    cin >> n >> m;
    dsu_set(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v);
    }
    cout << edge_count;
    return 0;
}

// Minimum Spanning Tree <<<<<<<

// Sample Input 0

// 5 7
// 1 2
// 2 3
// 3 4
// 4 5
// 4 1
// 2 4
// 5 3
// Sample Output 0

// 3
// Sample Input 1

// 3 3
// 1 2
// 2 3
// 1 3
// Sample Output 1

// 1