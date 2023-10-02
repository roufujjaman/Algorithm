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
bool cmp (Edge a, Edge b)
{
	return a.w < b.w;
}
int dsu_find(vector<int> &parent, int node)
{
	while (parent[node] != -1)
	{
		node = parent[node];
	}
	return node;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<Edge> ed;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ed.push_back({u, v, w});
	}
	sort(ed.begin(), ed.end(), cmp);
	vector<int> parent(n + 1, -1);
	vector<int> parent_size(n + 1, 1);
	int mst_length = 0;
	for (Edge e: ed)
	{
		int leader_a = dsu_find(parent, e.u);
		int leader_b = dsu_find(parent, e.v);

		if (leader_a != leader_b)
		{
			mst_length += e.w;
			if (parent_size[leader_a] < parent_size[leader_b])
			{
				parent[leader_a] = leader_b;
				parent_size[leader_b] += parent_size[leader_a];
			}
			else
			{
				parent[leader_b] = leader_a;
				parent_size[leader_a] = parent_size[leader_b]; 
			}
		}
	}
	cout << mst_length << "\n";
	return 0;
}