class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 0)
        {
            int target = sum / 2;
            bool memo[n + 1][target + 1];
            for (int i = 0; i <= target; i++)
            {
                if (i == 0) memo[0][i] = 1;
                else memo[0][i] = 0;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= target; j++)
                {
                    if (nums[i - 1] <= j)
                    {
                        int with = memo[i - 1][j - nums[i - 1]];
                        int without = memo[i - 1][j];
                        memo[i][j] = with || without;
                    }
                    else
                    {
                        memo[i][j] = memo[i - 1][j];
                    }
                }
            }
            if (memo[n][target]) return true;
        }
        return false;
    }
};