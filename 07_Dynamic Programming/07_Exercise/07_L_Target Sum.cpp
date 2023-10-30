class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i: nums) sum += i;

        if (target > sum && target < -sum && (sum + target) % 2 == 1) return 0;

        int t = (sum + target) / 2;
        int mem[n + 1][t + 1];
        mem[0][0] = 1;
        for (int j = 1; j <= t; j++) mem[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= t; j++)
            {
                if (nums[i - 1] <= j)
                {
                    mem[i][j] = mem[i - 1][j - nums[i - 1]] + mem[i - 1][j];
                }
                else
                {
                    mem[i][j] = mem[i - 1][j];
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= t; j++)
            {
                cout << mem[i][j] << " ";
            }
            cout << "\n";
        }
        return mem[n][t];
    }
};