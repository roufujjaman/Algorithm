class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += nums[i];
        }
        if (s % 2 != 0) return false;
        // target
        int t = s / 2;
        int mem[n + 1][t + 1];
        // basecase
        mem[0][0] = 1;
        for (int i = 1; i <= t; i++)
        {
            mem[0][i] = 0;
        }

        // dp
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= t; j++)
            {
                if (nums[i - 1] <= j)
                {
                    mem[i][j] = mem[i - 1][j - nums[i - 1]] || mem[i - 1][j];
                }
                else
                {
                    mem[i][j] = mem[i - 1][j];
                }
            }
        }
        // cheking if mem[n][t] target = sum / 2;
        if (mem[n][t]) return true;
        return false;
    }
};