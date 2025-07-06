class Solution {
public:
    int f(int n, vector<int>& nums, vector<vector<int>>& dp) {
        if(n == 0) return nums[0];
        if(n < 0) return 0;

        if(dp[n][n] != -1) return dp[n][n] ;

        return dp[n][n] = max(f(n-1,nums,dp),(f(n-2,nums,dp) + nums[n]));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return f(n-1,nums,dp);
    }
};