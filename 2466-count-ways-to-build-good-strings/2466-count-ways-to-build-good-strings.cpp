class Solution {
public:
    int MOD = 1000000007;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);

        if (zero <= high) dp[zero] = 1;
        if (one <= high) dp[one] += 1;

        for (int i = 0; i <= high; i++) {
            if (i - zero >= 0) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            if (i - one >= 0) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
        }

        int result = 0;
        for (int i = low; i <= high; i++) {
            result = (result + dp[i]) % MOD;
        }

        return result;
    }
};