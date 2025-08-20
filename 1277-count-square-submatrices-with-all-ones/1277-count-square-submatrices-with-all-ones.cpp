class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int m = matrix.size(), n= matrix[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        
        if(matrix[i][j] == 0) return 0;

        if(dp[i][j] != -1) {
            return dp[i][j] ;
        }
        int right = solve(i,j+1,matrix,dp);
        int diagonal = solve(i+1,j+1,matrix,dp);
        int bottom = solve(i+1,j,matrix,dp);

        return dp[i][j] = 1 + min({right,diagonal,bottom});
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int count =0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                count += solve(i,j,matrix,dp);
            }
        }
        return count ;
    }
};