#define offset 10000

class Solution {
public:
    int memo(vector<int>& nums,vector<vector<int>>& dp,int &target, int i,int sum) {
        int n = nums.size() ;
        if(i >= n) {
            return sum == target ;
        }

        if(dp[i][target+sum + offset] != -1) {
            return dp[i][target+sum + offset] ;
        }

        int numWays = 0;
        numWays += memo(nums,dp,target,i+1, sum+nums[i]);
        numWays += memo(nums,dp,target,i+1, sum-nums[i]);

        return dp[i][target + sum + offset] = numWays ;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n+1,vector<int>(2*sum +1 + offset,-1));

        return memo(nums,dp,target,0,0);
    }
};