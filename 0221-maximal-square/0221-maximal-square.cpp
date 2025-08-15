//This is just backtracking with dp. Kind of 01 knapsack dp, but there is only take.
//There isn't a case where we don't take. By default we encouter a 1 then we just increase
//from there.

class Solution {
public:
    int memo(vector<vector<char>>& matrix, int row, int col, int& ans, vector<vector<int>>& dp) {
        if(row >= matrix.size() || col >= matrix[0].size()) {
            return 0;
        }
        if(dp[row][col] != -1) {
            return dp[row][col] ;
        }
        int bottom = memo(matrix,row+1,col,ans,dp);
        int right = memo(matrix,row,col+1,ans,dp);
        int diagonal = memo(matrix,row+1,col+1,ans,dp);
        if(matrix[row][col] != '0') {
            dp[row][col] = 1 + min({right,diagonal,bottom});
            ans = max(ans,dp[row][col]);
            return dp[row][col] ;
        } else {
            return dp[row][col] = 0;
        }
        return dp[row][col] ;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        int mem = memo(matrix, 0, 0, ans, dp);
        return ans * ans ;
    }
};