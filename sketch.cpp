#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 2;
int dist[101][101];
int main()
{
    // Write your code here
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int y, z, n;
        cin >> y >> z;
        cout << dist[y][z] << "\n";
    }
    return 0;
}