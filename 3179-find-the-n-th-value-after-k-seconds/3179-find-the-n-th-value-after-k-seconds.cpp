class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
      const int MOD = 1000000007;
        vector<long long> prev(n, 1), curr(n);

        // Repeat for k seconds
        for (int i = 1; i <= k; ++i) {
            curr[0] = 1;  // Since arr[0] is always 1
            for (int j = 1; j < n; ++j) {
                curr[j] = (curr[j-1] + prev[j]) % MOD;
            }
            prev = curr;  // Update previous array
        }

        return prev[n-1] % MOD;
    }
};