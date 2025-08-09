class Solution {
public:
    pair<int, int> count(string& s) {
        pair<int, int> count01 = {0, 0};
        for (const char& ch : s) {
            if (ch == '0') {
                count01.first++;
            } else {
                count01.second++;
            }
        }
        return count01;
    }

    int memo(vector<string>& strs, int m, int n, int index,vector<vector<vector<int>>>& dp) {
        if (index == strs.size()) {
            if (m >= 0 && n >= 0) {
                return 1;
            }
            return 0;
        }
        if(dp[index][m][n] != -1){
            return dp[index][m][n] ;
        }

        pair<int, int> count01 = count(strs[index]);
        int count0 = count01.first, count1 = count01.second;

        int take = 0, notTake = 0;
        if (count01.first <= m && count01.second <= n) {
            take = 1 + memo(strs, m - count0, n - count1, index + 1,dp);
            notTake = memo(strs, m, n, index + 1,dp);
        } else {
            notTake = memo(strs, m, n, index + 1,dp);
        }
        return dp[index][m][n] = max(take,notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>> (m+1,vector<int>(n+1,-1)));
        return memo(strs, m, n, 0,dp) -1;
    }
};