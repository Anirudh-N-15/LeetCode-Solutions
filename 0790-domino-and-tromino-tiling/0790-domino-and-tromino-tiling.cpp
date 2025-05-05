class Solution {
public:
    int numTilings(int n) {
        vector<int> dp(n+1,0);
        int MOD = 1000000007;
        if(n <= 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        dp[1] = 1, dp[2] = 2, dp[3] = 5; 

        for(int i=4; i <= n; i++) {
            dp[i] = ((long long)dp[i-1] * 2 + (long long)dp[i-3]) % MOD ;
        }
        return dp[n] ;
    }
};