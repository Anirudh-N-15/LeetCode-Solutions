class Solution {
public:
    int found(vector<int>& nums,vector<vector<int>>& dp,int i,int s,int n,int target,int sum) {
        if(i == n && s == target) {
            return 1;   //Found one way to reach target sum
        }
        if(i >= n) {
            return 0;   //Found no way to reach target sum
        }
        if(dp[i][s + sum] != -1) {
            return dp[i][s + sum] ;
        }

        return dp[i][s + sum] = found(nums,dp,i+1,s + nums[i],n,target,sum) + 
                                found(nums,dp,i+1,s- nums[i],n,target,sum) ;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(),sum = 0;
        for(const int &num : nums) {
            sum += num ;
        }
        vector<vector<int>> dp(n+1,vector<int>(sum*2 +1,-1));

        return found(nums,dp,0,0,n,target,sum);
    }
};