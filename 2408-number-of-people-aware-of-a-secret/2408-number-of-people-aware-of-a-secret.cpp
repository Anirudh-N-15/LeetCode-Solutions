class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        long long share = 0, mod = 1000000007;

        for (int t = 2; t <= n; t++) {
            if (t - delay > 0) {
                share = (share + dp[t - delay] + mod ) % mod;
            }
            if (t - forget > 0) {
                share = (share - dp[t - forget] + mod) % mod;
            }
            dp[t] = share;
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            ans = (ans + dp[i]) % mod;
        }
        return (int)ans;
    }
};