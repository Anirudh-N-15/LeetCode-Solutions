class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n == 1) {
            return costs[0] + 1;
        }
        if(n == 2) {
            return min(costs[1] + costs[0] + 1 + 1 , costs[1] + 4);
        }
        vector<int> dp(n+1,-1);
        dp[0] = 0, dp[1] = costs[0] + 1 , dp[2] = min(costs[1] + dp[1]+1 , costs[1] + 4);

        for(int i = 3;i<=n;i++) {
            int step1 = dp[i-3] + costs[i-1] + 9 ;
            int step2 = dp[i-2] + costs[i-1] + 4 ;
            int step3 = dp[i-1] + costs[i-1] + 1 ;
            dp[i] = min({step1,step2,step3});
        }
        return dp[n];
    }
};