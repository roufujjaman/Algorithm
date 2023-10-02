#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int parent[100001];
    int parent_size[100001];
    void dsu_set(int V)
    {
        for (int i = 0; i <= V; i++)
        {
            parent[i] = -1;
            parent_size[i] = 1;
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
    int dsu_union(int a, int b)
    {
        if (parent_size[a] < parent_size[b])
        {
            parent[a] = b;
            parent_size[b] += parent_size[a];
        }
        else
        {
            parent[b] = a;
            parent_size[a] += parent_size[b];
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        dsu_set(V);
        map<pair<int, int>, bool> mp;
        for (int u = 0; u < V; u++)
        {
            for (int v: adj[u])
            {
                if (mp[{u, v}] == true) continue;
                mp[{v, u}] = true;
                // if (v > u) continue;
                int leader_a = dsu_find(u);
                int leader_b = dsu_find(v);
                
                if (leader_a == leader_b) return true;
                dsu_union(leader_a, leader_b);
                
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends