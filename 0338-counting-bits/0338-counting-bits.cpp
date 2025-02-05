class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> dp(n+1,0);
        dp[0] = 0;

        for(int i=0;i<=n;++i){
            dp[i] = dp[i >> 1] + (i & 1) ; //dp[i <<1] means i/2 and (i &1) checks and if odd
        }
        return dp;
    }
};