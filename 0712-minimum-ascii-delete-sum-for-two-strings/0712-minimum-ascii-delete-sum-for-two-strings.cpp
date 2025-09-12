class Solution {
public:
    int memo(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        int n = s1.size(), m = s2.size();
        if (i == n || j == m) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            return dp[i][j] = s1[i] + memo(s1, s2, i + 1, j + 1, dp);
        } else {
            int p1 = memo(s1, s2, i + 1, j, dp);
            int p2 = memo(s1, s2, i, j + 1, dp);
            return dp[i][j] = max(p1, p2);
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int sum1 = 0, sum2 = 0;
        for (const char& ch : s1) {
            sum1 += ch;
        }
        for (const char& ch : s2) {
            sum2 += ch;
        }

        return sum1 + sum2 - (2 * memo(s1,s2,0,0,dp)) ;
    }
};