class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int currSum = 0;
        int count = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < n; ++i) {
            char ch = s[n - 1 - i];
            if (ch == '1') {
                if (i < bits && currSum + (1 << i) <= k) {
                    currSum += 1 << i;
                    count++;
                }
            } else {
                count++;
            }
        }
        return count;
    }
};