#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
const long long int INF = 1e18;
vector<pair<long long int, long long int>> adj[N];
vector<long long int> dist(N, INF);
bool bellmanford (int source, int n)
{
    dist[source] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (pair<int, int> e: adj[u])
            {
                int v = e.first;
                int w = e.second;
                if (i == n && dist[u] != INF && dist[u] + (long long int)w < dist[v])
                {
                    return true;
                }
                if (dist[u] != INF && dist[u] + (long long int)w < dist[v])
                {
                    dist[v] = dist[u] + (long long int)w;
                }
            }
        }
    }
    return false;
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
    }
    int source, query;
    cin >> source >> query;
    bool cycle = bellmanford(source, n);
    if (!cycle)
    {
        for (int i = 0; i < query; i++)
        {
            int d;
            cin >> d;
            if (dist[d] != INF) cout << dist[d] << "\n";
            else cout << "Not Possible" << "\n";
        }
    }
    else cout << "Negative Cycle Detected";
    return 0;
}


// Bellman Ford <<<<<<

// Sample Input 0

// 5 7
// 1 2 10
// 1 3 -2
// 3 2 1
// 2 4 7
// 3 4 -3
// 4 5 5
// 2 5 2
// 1
// 5
// 1
// 2
// 3
// 4
// 5
// Sample Output 0

// 0
// -1
// -2
// -5
// 0
// Sample Input 1

// 5 7
// 1 2 10
// 1 3 -2
// 3 2 1
// 2 4 7
// 3 4 -3
// 4 5 5
// 2 5 2
// 5
// 5
// 1
// 2
// 3
// 4
// 5
// Sample Output 1

// Not Possible
// Not Possible
// Not Possible
// Not Possible
// 0
// Sample Input 2

// 5 8
// 1 2 -2
// 1 3 -10
// 3 2 1
// 2 4 7
// 4 3 -3
// 4 5 5
// 2 5 2
// 4 1 1
// 1
// 5
// 1
// 2
// 3
// 4
// 5
// Sample Output 2

// Negative Cycle Detected