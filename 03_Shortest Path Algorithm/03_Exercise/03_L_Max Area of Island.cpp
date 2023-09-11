class Solution {
public:
    int n, m;
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int visited[50][50];
    int max_area = 0;
    bool is_valid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int dfs(int i, int j, vector<vector<int>> g, int area = 0)
    {
        visited[i][j] = true;
        area++;
        for (pair<int, int> d: direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (is_valid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 0)
            {
                area = area + dfs(ni, nj, g);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] != 0)
                {
                    int current_area = dfs(i, j, grid);
                    max_area = max(max_area, current_area);
                }
            }
        }
        return max_area;
    }
};