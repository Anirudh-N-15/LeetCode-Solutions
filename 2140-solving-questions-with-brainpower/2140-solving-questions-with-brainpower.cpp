class Solution {
public:
    long long mostPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<long long> dp(n,0);

        for(int i= n-1;i>=0;--i){
            int index = i + nums[i][1] + 1;
            if(index < n){
                dp[i] = dp[index] + nums[i][0] ;
            }else {
                dp[i] = nums[i][0];
            }
            if(i < n -1){
                dp[i] = max(dp[i], dp[i + 1]);
            }
        }
        return dp[0] ;
    }
};