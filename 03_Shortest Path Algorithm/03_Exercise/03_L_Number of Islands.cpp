class Solution {
public:
    int N = 300;
    vector<pair<int,int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    int visited[300][300];
    bool is_valid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    void dfs(int i, int j, vector<vector<char>>& g)
    {
        visited[i][j] = true;
        for (pair<int, int> d:direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (is_valid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '0')
            {
                dfs(ni, nj, g);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count_islands = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j]) continue;
                if (grid[i][j] == '0') continue;
                count_islands++;
                dfs(i, j, grid);
            }
        }
        return count_islands;
    }
}