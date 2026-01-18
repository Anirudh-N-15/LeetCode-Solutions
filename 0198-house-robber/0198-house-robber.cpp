class Solution {
public:
    int memo(vector<int>& nums,vector<int>& dp,int i) {
        int n = nums.size() ;
        if(i >= n) return 0 ;

        if(dp[i] != -1) return dp[i] ;

        return dp[i] = max(memo(nums,dp,i+1), nums[i] + memo(nums,dp,i+2));
    }


    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n+1,-1) ;

        return memo(nums,dp,0) ;
    }
};