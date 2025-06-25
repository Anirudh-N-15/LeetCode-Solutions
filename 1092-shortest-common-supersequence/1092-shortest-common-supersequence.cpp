//The idea here is to add both strings and then find the length of the LCS(longest common
//subsequence) and then subtract it from the added string's length.
//This works only for finding the length. The idea here is similar.
//From the constructed table we backtrack to find the answer.
//Follow the code to know how it works.

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i-1] == t[j-1]) { //We found a match
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //dp[n][m] contains the length of the LCS

        int i=n,j=m;
        string ans = "";
        while(i > 0 && j > 0) {
            if(s[i-1] == t[j-1]) {
                //Add to string if characters are same
                ans.push_back(s[i-1]);
                i-- ;
                j-- ;
            } else if(dp[i - 1][j] > dp[i][j-1]) {
                //If top has higher value add it to string
                ans.push_back(s[i-1]);
                i-- ;
            } else {
                //If left side has higher value then take from second string
                ans.push_back(t[j-1]);
                j-- ;
            }
        }

        //Complete if there are remaining characters in the string
        while(i > 0) {
            ans.push_back(s[i-1]);
            i-- ;
        }
        while(j > 0) {
            ans.push_back(t[j-1]);
            j-- ;
        }

        reverse(ans.begin(),ans.end());
        return ans ;

    }
};