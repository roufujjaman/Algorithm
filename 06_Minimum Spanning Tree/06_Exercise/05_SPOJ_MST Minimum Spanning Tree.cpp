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
long long int prims(int source, vector<pair<int, int>> edges[], int n)
{
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({source, source, 0});
	vector<int> visited(n + 1, 0);
	long long int mst_length = 0;
	while (!pq.empty())
	{
		int v = pq.top().v;
		int w = pq.top().w;
		pq.pop();

		if (visited[v]) continue;
		visited[v] = true;
		mst_length += (long long int)w;

		for (pair<int, int> child: edges[v])
		{
			if (!visited[child.first])
			{
				pq.push({v, child.first, child.second});
			}
		}
	}
	return mst_length;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> ed[n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ed[u].push_back({v, w});
		ed[v].push_back({u, w});
	}
	cout << prims(1, ed, n);
	return 0;
}



// Input:
// 4 5
// 1 2 10
// 2 3 15
// 1 3 5
// 4 2 2
// 4 3 40

// Output:
// 17