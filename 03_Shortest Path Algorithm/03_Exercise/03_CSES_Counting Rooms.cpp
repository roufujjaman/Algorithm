#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 11;
vector<string> g;
bool visited[N][N];
int n, m;
bool is_valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int i, int j)
{
    if (is_valid(i, j) == false) return;
    if (visited[i][j] == true) return;
    
    if (g[i][j] == '#') return;

    visited[i][j] = true;
    
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i + 1, j);
    dfs(i, j - 1);   
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string input_val;
        cin >> input_val;
        g.push_back(input_val);
    }
    int count_room = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '#') continue;
            if (visited[i][j] == true) continue;
            dfs(i, j);
            count_room++;
        }
    }
    cout << count_room;
    return 0;
}
