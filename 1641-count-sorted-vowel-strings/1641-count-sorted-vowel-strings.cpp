class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        return recurse(n, 0, 0,dp);
    }
    int recurse(int n, int size, int idx,vector<vector<int>>& dp){
        if(size==n)return 1;
        if(idx==5)return 0;

        if(dp[size][idx] != -1) return dp[size][idx];

        int take = recurse(n, size+1, idx,dp);
        int non_take = recurse(n, size, idx+1,dp);

        return dp[size][idx] = take+non_take;
    }
};