class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> sources;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1) sources.push({i, j});
            }
        }
        vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int level = -1;
        while (!sources.empty())
        {
            level++;
            int q_size = sources.size();
            
            while (q_size--)
            {
                int i = sources.front().first;
                int j = sources.front().second;
                sources.pop();

                for (pair<int, int> d: direction)
                {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] == 1)
                    {
                        continue;
                    }
                    grid[ni][nj] = 1;
                    sources.push({ni, nj});
                }
            }
        }
        return (level == 0 || level == -1)? -1: level;
    }
};