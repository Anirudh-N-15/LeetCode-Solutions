//For each char we have the option whether to choose it or not. Therefore, if we encounter
//a match either choose both or dont chose. Then memoize, voila

// class Solution {
// public:
//     int memo(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
//         if(j < 0) return 1; //We have found one match
//         if(i < 0) return 0; //We have not found a match so far

//         if(dp[i][j] != -1) return dp[i][j] ;

//         if(s[i] == t[j]) { //We have found a match now
//             return dp[i][j] = memo(i-1,j-1,s,t,dp) //We have found a match and chose both
//                             + memo(i-1,j,s,t,dp); //We didn't choose in this path
//         } else {    //No match to be found
//             return dp[i][j] = memo(i-1,j,s,t,dp);
//         }
//     }


//     int numDistinct(string s, string t) {
//         int n = s.size(), m = t.size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));

//         return memo(n-1,m-1,s,t,dp);
//     }
// };


class Solution {
    public:
        int numDistinct(string s, string t) {
            int n = s.size(), m = t.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));

            for(int i=0;i<=n;i++) {
                dp[i][0] = 1;
            }

            for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                    if(s[i-1] == t[j-1]) {
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-1] ;
                    } else {
                        dp[i][j] = dp[i-1][j] ;
                    }
                }
            }
            return dp[n][m];
        }
};