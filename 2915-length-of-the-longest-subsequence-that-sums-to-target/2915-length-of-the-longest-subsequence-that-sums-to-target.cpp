class Solution {
public:
    int memo(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        int n = nums.size();
        if(i == n && target > 0) return -1e6;
        if(i == n || target == 0) return 0;

        if(dp[i][target] != -1) return dp[i][target];

        if(nums[i] <= target){
            int take = memo(nums,i+1,target-nums[i],dp) + 1;
            int notTake = memo(nums,i+1,target,dp);
            return dp[i][target] = max(take,notTake);
        } else {
            return dp[i][target] = memo(nums,i+1,target,dp);
        }
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

        return memo(nums,0,target,dp) < 0 ? -1 : memo(nums,0,target,dp);
    }
};