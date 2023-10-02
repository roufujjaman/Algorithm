#include <bits/stdc++.h>

using namespace std;
const long long int INF = 1e18;
long long int dist[101][101];
void init_dist(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i != j) dist[i][j] = INF;
        }
    }
}
void floyd_warshall(int n)
{    
    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                if (dist[u][k] != INF && dist[k][v] != INF)
                {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }
}
int main()
{
    // Write your code here
    int n, m;
    cin >> n >> m;
    init_dist(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], (long long int)w);
    }
    floyd_warshall(n);
    int query;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] != INF) cout << dist[u][v] << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}


// Sample Input 0

// 4 7
// 1 2 10
// 2 3 5
// 3 4 2
// 4 2 3
// 3 1 7
// 2 1 1
// 1 4 4
// 6
// 1 2
// 4 1
// 3 1
// 1 4
// 2 4
// 4 2
// Sample Output 0

// 7
// 4
// 6
// 4
// 5
// 3
// Sample Input 1

// 4 4
// 1 2 4
// 2 3 4
// 3 1 2
// 1 2 10
// 6
// 1 2
// 2 1
// 1 3
// 3 1
// 2 3
// 3 2
// Sample Output 1

// 4
// 6
// 8
// 2
// 4
// 6