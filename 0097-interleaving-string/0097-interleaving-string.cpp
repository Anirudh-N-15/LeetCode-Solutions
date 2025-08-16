class Solution {
public:
    int m,n,l; 
    vector<vector<int>> dp;
    bool solve(int i,int j,string& s1, string& s2, string& s3) {
        int k = i + j;

        if(k == l) return true ;
        if(i == s1.size() || j == s2.size()) {
            return true ;
        }
        if(dp[i][j] != -1) return dp[i][j] ;
        
        int ans = false ;
        if(s1[i] == s3[k]) {
            ans = ans || solve(i+1,j,s1,s2,s3);
        }
        if(s2[j] == s3[k]) {
            ans = ans || solve(i,j+1,s1,s2,s3);
        }
        return dp[i][j] = ans ;
    }

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size(), n = s2.size(), l = s3.size();
        if( n + m != l) return false ;

        dp.assign(m+1,vector<int>(n+1,-1));

        return solve(0,0,s1,s2,s3);
    }
};