class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int &num : nums){
            sum += num;
        }
        if((sum & 1) != 0) return false ;

        int targetSum = sum/2 ;
        vector<bool> dp(targetSum+1,false);
        dp[0] = true ;

        for(int &num : nums){
            for(int i = targetSum;i >= num; --i){
                dp[i] = dp[i] || dp[i - num];
                if(dp[targetSum]) return true ;
            }
        }
        return dp[targetSum] ;
    }
};