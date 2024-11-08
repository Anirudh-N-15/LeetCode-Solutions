class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0 ;

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<long long >> dp(row,vector<long long>(col,0));

        dp[0][0] = 1 ;

        for(int i=1;i<col;++i){
            if(obstacleGrid[0][i]==1){
                while(i<col){
                    dp[0][i] = 0 ;
                    i++ ;
                }
            }
            else{
                dp[0][i] =1 ;
            }
        }

        for(int i=1;i<row;++i){
            if(obstacleGrid[i][0]==1){
                while(i<row){
                    dp[i][0] = 0 ;
                    i++ ;
                }
            }
            else{
                dp[i][0] =1 ;
            }
        }

        for(int i=1;i<row;++i){
            for(int j=1;j<col;++j){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0 ;
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
                }
            }
        }
        return dp[row-1][col-1];
    }
};