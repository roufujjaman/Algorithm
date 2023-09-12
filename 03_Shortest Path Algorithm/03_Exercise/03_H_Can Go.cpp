#include <bits/stdc++.h>

using namespace std;
const int N = 1e3;
int n, m;
vector<pair<int, int>> g[N];
int visited[N];
vector<long long int> dist(N, INT_MAX);
void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    visited[s] = true;
    pq.push({dist[s], s});
    
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        
        visited[u] = true;
        
        for (pair<int, int> vpair: g[u])
        {
            int v = vpair.first;
            int w = vpair.second;
            if (!visited[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}


int main()
{
    // Write your code here
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    int source, query_count;
    cin >> source >> query_count;
    dijkstra(source);
    for (int i = 0; i < query_count; i++)
    {
        long long int v, w;
        cin >> v >> w;
        if (w >= dist[v]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

// Sample Input 0

// 5 7
// 1 2 10
// 1 3 2
// 3 2 1
// 2 4 7
// 3 4 2
// 4 5 5
// 2 5 2
// 1
// 5
// 1 0
// 2 5
// 3 1
// 4 4
// 5 6
// Sample Output 0

// YES
// YES
// NO
// YES
// YES