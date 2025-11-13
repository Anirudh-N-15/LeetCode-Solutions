class Solution {
public:
    int memo(vector<int>& nums,vector<vector<int>>& dp, int target,int s, int i,int sum) {
        if(i < 0) {
            if(s == target) return 1 ;
            else return 0 ;
        }

        if(dp[i][s + sum] != -1) return dp[i][s + sum] ;

        return dp[i][s + sum ] = memo(nums,dp,target,s + nums[i],i-1,sum) + 
                                   memo(nums,dp,target,s - nums[i],i-1,sum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>> dp(n+1,vector<int>(sum*2 +1,-1));

        return memo(nums,dp,target,0,n-1,sum);
    }
};