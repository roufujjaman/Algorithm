#include<bits/stdc++.h>
using namespace std;
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}
int main()
{
    int n, m, src;
    cin >> n >> m >> src;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] =  {u, v, w};
    }
    vector<int> dist = bellmonFord(n, m, src, edges);
    for (int i: dist)
    {
        cout << i << " ";
    }
    return 0;
}

// 4 4 1
// 1 2 4
// 1 3 3
// 2 4 7
// 3 4 -2


// 0 4 3 1 

