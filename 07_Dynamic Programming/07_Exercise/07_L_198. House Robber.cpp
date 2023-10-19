class Solution {
public:
    int fn(int i, vector<int>& nums, vector<int>& memo)
    {
        if (i < 0) return 0;
        if (memo[i] != -1) return memo[i];
        int withCurrent = fn(i - 2, nums, memo) + nums[i];
        int withoutCurrent = fn(i - 1, nums, memo);
        return memo[i] = max(withCurrent, withoutCurrent);
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return fn(nums.size() - 1, nums, memo);
    }
};