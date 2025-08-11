class Solution {
public:
    int memo(vector<int>& nums, int target, vector<int>& dp) {
        if (target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }
        if (dp[target] != -1) {
            return dp[target];
        }

        int ans = 0;
        for (const auto& num : nums) {
            ans += memo(nums, target - num, dp);
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);

        return memo(nums, target, dp);
    }
};