#include <bits/stdc++.h>
using namespace std;
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
		bool operator() (Edge a, Edge b)
		{
			return a.w > b.w;
		}
};
const int N = 1e5 + 1;
vector<pair<int, int>> ed[N];
int visited[N];
vector<int> mst_edge_weights;
void prims(int source)
{
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({source, source, 0});
 
	while (!pq.empty())
	{
		int v = pq.top().v;
		int w = pq.top().w;
		pq.pop();
		if (visited[v]) continue;
		visited[v] = true;
		mst_edge_weights.push_back(w);
 
		for (int i = 0; i < ed[v].size(); i++)
		{
			pair<int, int> child = ed[v][i];
			if (!visited[child.first])
			{
				pq.push({v, child.first, child.second});
			}
		}
	}	
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ed[u].push_back({v, w});
		ed[v].push_back({u, w});
	}
	prims(1);
	mst_edge_weights.erase(mst_edge_weights.begin());
	if (n == mst_edge_weights.size() + 1)
	{
		long long int sum = 0;
		for (int w: mst_edge_weights)
		{
			sum += (long long)w;
		}
		cout << sum;
	}
	else
	{
		cout << "IMPOSSIBLE" << "\n";
	}
	return 0;
}