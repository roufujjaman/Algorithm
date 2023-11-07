class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = INT_MAX - 1;
        int n = coins.size();
        int mem[n + 1][amount + 1];
        mem[0][0] = 0;
        for (int j = 1; j <= amount; j++) mem[0][j] = INF;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    mem[i][j] = min(1 + mem[i][j - coins[i - 1]], mem[i - 1][j]);
                }
                else
                {
                    mem[i][j] = mem[i - 1][j];
                }
            }
        }
        if (mem[n][amount] != INF) return mem[n][amount];
        return -1;
    }
};