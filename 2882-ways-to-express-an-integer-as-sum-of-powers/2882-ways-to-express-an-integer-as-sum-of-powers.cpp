class Solution {
public:
    const int mod = 1e9 + 7;

    int memo(int n, int x, int index, vector<int>& nums,
             vector<vector<int>>& dp) {
        if (n < 0) {
            return 0;
        }
        if (index == nums.size()) {
            if (n == 0) {
                return 1;
            }
            return 0;
        }
        if (dp[n][index] != -1) {
            return dp[n][index];
        }

        int take = 0, notTake = 0;
        int currNum = 1;
        for (int j = 0; j < x; j++) {
            currNum *= nums[index];
            if (currNum > n) break; // no need to go further
        }
        if (x == 1) {
            currNum = nums[index];
        }
        if (currNum <= n) {
            take = memo(n - currNum, x, index + 1, nums, dp) % mod;
            notTake = memo(n, x, index + 1, nums, dp) % mod;
        } else {
            notTake = memo(n, x, index + 1, nums, dp) % mod;
        }
        return dp[n][index] = (take % mod + notTake % mod) % mod;
    }

    int numberOfWays(int n, int x) {
        vector<int> nums(301, 0);
        for (int i = 1; i <= 300; i++) {
            nums[i] = i;
        }
        vector<vector<int>> dp(n + 1, vector<int>(301, -1));
        return memo(n, x, 1, nums, dp);
    }
};