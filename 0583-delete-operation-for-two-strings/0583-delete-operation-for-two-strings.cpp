//The logic here is to return(delete) the number of chars that is extra 
//from both the strings.As we are adding both the strings we are getting 
//double the number of LCS. That is why we subtract LCS*2 ;

class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] +1;
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n + m - (2*dp[n][m]) ;
    }
};