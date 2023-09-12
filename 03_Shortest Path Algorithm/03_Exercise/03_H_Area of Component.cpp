#include <bits/stdc++.h>

using namespace std;
const int N = 1e3;
vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int visited[N][N];
vector<string> g;
int min_area = INT_MAX;
bool is_valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int dfs(int i, int j, int sz = 0)
{
    if (visited[i][j]) return 0;
    visited[i][j] = true;
    sz++;
    for (pair<int, int> d: direction)
    {
        int ni = i + d.first;
        int nj = j + d.second;
        if (is_valid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '-')
        {
            sz = sz + dfs(ni, nj);
        }
    }
    return sz;
}

int main()
{
    // Write your code here
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string input_str;
        cin >> input_str;
        g.push_back(input_str);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && g[i][j] != '-')
            {
                min_area = min(min_area, dfs(i, j));
            }
        }
    }
    if ((min_area == 0)|(min_area == INT_MAX)) min_area = -1;
    cout << min_area;
    return 0;
}

// Sample Input 0

// 6 5
// ..-..
// ..-..
// -----
// .-...
// .----
// .....
// Sample Output 0

// 3