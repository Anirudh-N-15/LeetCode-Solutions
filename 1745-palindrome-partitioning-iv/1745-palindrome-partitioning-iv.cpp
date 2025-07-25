class Solution {
public:
    bool isPalindrome(const string& s,int i,int j,vector<vector<int>>& dp) {
        if(i >= j) return true ;

        if(dp[i][j] != -1) return dp[i][j]; 

        if(s[i] == s[j]) {
            return dp[i][j] = isPalindrome(s,i+1,j-1,dp);
        }
        return dp[i][j] = false ;
    }

    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=1;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(isPalindrome(s,0,i-1,dp) && isPalindrome(s,i,j-1,dp) && isPalindrome(s,j,n-1,dp)){
                    return true ;
                }
            }
        }
        return false ;
    }
};