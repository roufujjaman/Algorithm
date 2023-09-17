#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u;
        int v;
        int w;
        Edge(int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge input_edge(u, v, w);
        edges.push_back(input_edge);
    }
    int source;
    cin >> source;

    vector<int> dist(n + 1, INT_MAX); // index = node, val = distance;
    dist[source] = 0; // declare the source node; 
    
    for (int i = 0; i < n - 1; i++) // all edges to relax n - 1 times;
    {
        for (Edge ed: edges)
        {
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) // relexation
            {
                dist[v] = dist[u] + w;
            }
        }
        
        // print - each relaxation
        cout << "Iteration " << i + 1 << "\n";
        for (int i = 1; i <= n; i++)
        {
            cout << source << " > " << i << ": " << dist[i] << "\n";
        }
    }    
    return 0;
}

// 4 4
// 2 3 2
// 1 4 10
// 3 4 -2
// 1 2 5
// 1
