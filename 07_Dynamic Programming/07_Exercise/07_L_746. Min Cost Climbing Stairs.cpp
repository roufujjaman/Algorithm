class Solution {
public:
    int fn(int i, vector<int>& cost, vector<int>& memo)
    {
        if (i == 0) return cost[i];
        if (i == 1) return cost[i];
        if (memo[i] != -1) return memo[i]; 
        int left = cost[i] + fn(i - 1, cost, memo);
        int right = cost[i] + fn(i - 2, cost, memo);
        return memo[i] = min(left, right); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(1001, -1);
        cost.push_back(0);
        return fn(cost.size() - 1, cost, memo);
    }
};