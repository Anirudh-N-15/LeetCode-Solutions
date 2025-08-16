class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if( n <= 1) return 1 ;

        if(dp[n] != -1) return dp[n] ;

        int ways = 0;
        for(int i=1;i<=n;i++) {
            int left = solve(i - 1, dp);
            int right = solve(n - i, dp) ;
            ways += left * right ;
        }
        return dp[n] = ways ;
    }

    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};