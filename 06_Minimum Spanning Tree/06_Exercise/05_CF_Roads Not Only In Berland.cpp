#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int parent[N];
int parent_size[N];
queue<pair<int, int>> edges;
int dsu_set(int n)
{
	for (int i = 0; i <= n; i++)
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
	int leader_a = dsu_find(a);
	int leader_b = dsu_find(b);

	if (leader_a == leader_b) edges.push({a, b});
	else
	{
		if (parent_size[leader_a] < parent_size[leader_b])
		{
			parent[leader_a] = leader_b;
			parent_size[leader_b] += parent_size[leader_a]; 
		}
		else
		{
			parent[leader_b] = leader_a;
			parent_size[leader_a] += parent_size[leader_b];
		}
	}
}
int main()
{
	int n;
	cin >> n;
	dsu_set(n);
	for (int i = 1; i <= n; i++)
	{
		int u, v;
		cin >> u >> v;
		dsu_union(u, v);
	}
	cout << edges.size()  - 1 << "\n";
	for (int i = 1; i <= n; i++)
	{
		int leader_a = dsu_find(edges.front().first);
		int leader_b = dsu_find(i);
		if (leader_a != leader_b)
		{
			cout << edges.front().first << " " << edges.front().second << " ";
			cout << leader_a << " " << leader_b << "\n";
			dsu_union(leader_a, leader_b);
			edges.pop();
		}
	}
	return 0;
}

// input
// 2
// 1 2
// output
// 0

// input
// 7
// 1 2
// 2 3
// 3 1
// 4 5
// 5 6
// 6 7
// output
// 1
// 3 1 3 7