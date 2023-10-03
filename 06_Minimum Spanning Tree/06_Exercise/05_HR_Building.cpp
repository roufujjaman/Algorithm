#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
vector<pair<int, int>> adj[N];
vector<int> visited(N, 0);
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
class cmp
{
    public:
        bool operator()(Edge a, Edge b)
        {
            return a.w > b.w;
        }
};
pair<long long int, int> prims(int source)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push({source, source, 0});
    long long int mst_length = 0;
    int mst_size = -1;
    while (!pq.empty())
    {
        int v = pq.top().v;
        int w = pq.top().w;
        pq.pop();
        
        if (visited[v]) continue;
        visited[v] = true;
        mst_length += w;
        mst_size++;
        for (pair<int, int> child: adj[v])
        {
            if (!visited[child.first]) pq.push({v, child.first, child.second});
        }
    }
    return {mst_length, mst_size};
}
int main()
{
    // Write your code here
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    pair<long long int, int> mst = prims(1);
    if (mst.second == n - 1) cout << mst.first;
    else cout << -1;
    return 0;
}

// Minimum Spanning Tree (Prim's Algorithms) <<<<<<<

// Sample Input 0

// 5 7
// 1 2 10
// 1 3 5
// 3 2 4
// 2 4 1
// 3 4 2
// 4 5 3
// 1 5 2
// Sample Output 0

// 8
// Sample Input 1

// 3 2
// 1 2 10
// 2 1 2
// Sample Output 1

// -1