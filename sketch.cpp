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
        }
        else
        {
            parent[leader_a] = leader_b;
            parent_size[leader_b] += parent_size[leader_a]; 
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    vector<int> head;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == -1)
        {
            head.push_back(i);
        }
    }
    cout << head.size() - 1 << "\n";
    for (int i = 1; i < head.size(); i++)
    {
        cout << head[i - 1] << " " << head[i] << "\n";
    }
    return 0;
}


// 10 10
// 2 5
// 5 6
// 1 4
// 6 8
// 2 6
// 3 6
// 1 10
// 8 9
// 2 3
// 5 8