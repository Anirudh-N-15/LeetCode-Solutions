//Applying brute force to check whether it will pass or not. Purely recursive solution.
//Will implement top-down/Memoization later
//Got TLE for recursive approach. Hence memoizing

class Solution {
public:
    int LCS(string s, string t, int n, int m, vector<vector<int>>& dp) {
        //Base Condition
        if(n == 0 || m == 0) {
            return 0; //Since there is no common letter/subsequence when one of the string
                      //becomes length 0
        }
        if(dp[n][m] != -1) {
            return dp[n][m] ;
        }
        //Choice diagram

        //We have found a match
        if(s[n-1] == t[m-1]) {
            return dp[n][m] = 1 + LCS(s,t,n-1,m-1,dp) ; //Will call for shorter string 
        }
        //There is no match for the current letter
        else {
            return dp[n][m] =  max(LCS(s,t,n-1,m,dp), LCS(s,t,n,m-1,dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size() ;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int result =  LCS(text1,text2,n,m,dp);
        return result == -1 ? 0 : result ;
    }
};