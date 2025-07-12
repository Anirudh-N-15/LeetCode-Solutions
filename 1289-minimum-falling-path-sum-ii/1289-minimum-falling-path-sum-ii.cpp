//I got confused with this question. The question allows to chose not just adjacent columns 
//but all columns, other than the current one. So just loop through all other columns in the
//next row other than the current one

class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        if (j < 0 || j >= n)
            return 1e9;

        if (i == n - 1)
            return grid[i][j];

        if (dp[i][j] != 1e9)
            return dp[i][j];

        int rec = INT_MAX;
        for(int k=0;k<n;k++) {
            if(k != j){
                rec = min(rec,memo(i+1,k,grid,dp));
            }
        }

        return dp[i][j] = grid[i][j] + rec;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));

        int result = 1e9;
        for (int j = 0; j < n; j++) {
            result = min(result, memo(0, j, grid, dp));
        }

        return result;
    }
};