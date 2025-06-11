class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus = [](int cntA, int cntB) -> int {
            return ((cntA & 1) << 1) | (cntB & 1);
        };

        int n = s.size();
        int ans = INT_MIN;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) {
                    continue;
                }
                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cntA = 0, cntB = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;
                for (int right = 0; right < n; ++right) {
                    cntA += (s[right] == a);
                    cntB += (s[right] == b);
                    while (right - left >= k && cntB - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] =
                            min(best[left_status], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }
                    int right_status = getStatus(cntA, cntB);
                    if (best[right_status ^ 0b10] != INT_MAX) {
                        ans =
                            max(ans, cntA - cntB - best[right_status ^ 0b10]);
                    }
                }
            }
        }
        return ans;
    }
};