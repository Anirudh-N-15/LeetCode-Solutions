class Solution {
public:
    int numRollsToTarget(int n, int m, int x) {
        //2D array to store die value and sum
        vector<vector<int>> dp(n+1, vector<int>(x+1,0));
        dp[0][0] = 1;
        const int MOD = 1e9 + 7;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=x;j++) {
                for(int k=1;k<=m && j - k >= 0;++k) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j - k]) % MOD ;
                }
            }
        }
        return dp[n][x];
    }
};