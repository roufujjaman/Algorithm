class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int s, int weight[], int val[], int n) 
    { 
       // Your code here
        int dp[n + 1][s + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (i == 0 || j == 0) dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                if (weight[i - 1] <= j)
                {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][s];
    }
};