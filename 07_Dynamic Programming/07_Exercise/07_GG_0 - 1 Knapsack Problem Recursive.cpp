class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1005][1005];
    int knapsack(int s, int weight[], int val[], int n)
    {
        if (n == 0 || s == 0) return 0;
        if (dp[n][s] != -1) return dp[n][s];
        if (weight[n - 1] <= s)
        {
            return dp[n][s] = max(knapsack(s - weight[n - 1], weight, val, n - 1) + val[n - 1], knapsack(s, weight, val, n - 1));
        }
        else
        {
            return dp[n][s] = knapsack(s, weight, val, n - 1);
        }
    }
    int knapSack(int s, int weight[], int val[], int n) 
    { 
       // Your code here
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        return knapsack(s, weight, val, n);
    }
};