class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col));
        dp[0][0] = grid[0][0] ;

        for(int i=1;i<col;++i){
            dp[0][i] = dp[0][i-1] + grid[0][i] ;
        }
        for(int j=1;j<row;++j){
            dp[j][0] = dp[j-1][0] + grid[j][0] ;
        }

        for(int i=1;i<row;++i){
            for(int j=1;j<col;++j){
                dp[i][j] = min(grid[i][j]+dp[i-1][j],grid[i][j]+dp[i][j-1]);
            }
        }
        return dp[row-1][col-1];
    }
};