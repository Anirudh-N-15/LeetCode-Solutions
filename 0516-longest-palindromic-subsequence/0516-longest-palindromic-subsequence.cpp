class Solution {
public:
    int memo(const string&s,const string&t,int i,int j, vector<vector<int>>& dp) {
        if(i == -1 || j== -1) return 0;

        if(dp[i][j] != -1) return dp[i][j] ;

        if(s[i] == t[j]) {
            return dp[i][j] = 1 + memo(s,t,i-1,j-1,dp);
        } else {
            return dp[i][j] = max(memo(s,t,i-1,j,dp),memo(s,t,i,j-1,dp));
        }
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return memo(s,t,n-1,n-1,dp);
    }
};