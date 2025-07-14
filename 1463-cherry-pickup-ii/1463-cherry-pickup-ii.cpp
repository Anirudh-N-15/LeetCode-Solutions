class Solution {
public:
    int memo(int i, int j1, int j2, vector<vector<int>>& grid,  vector<vector<vector<int>>>& dp){
        int m = grid.size(), n = grid[0].size();

        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return -1e9 ;   //Out of bounds condtion
        }

        if(i == m-1){//both robots has reached the last row
            if(j1 == j2){//both robots are present in the same col
                return grid[i][j1]; //Only need to return only one of the values
            } else {
                return grid[i][j1] + grid[i][j2] ; //Return both values since diff columns
            }
        }

        if(dp[i][j1][j2] != -1e9) {
            return dp[i][j1][j2] ;
        }

        //Exploring all Paths
        int maxVal = -1e9;
        for(int a = -1; a <= 1 ; a++) {
            for(int b = -1; b <= 1; b++) {
                int currVal = 0;
                if(j1 == j2){
                    currVal = grid[i][j1] ;
                } else {
                    currVal = grid[i][j1] + grid[i][j2] ;
                }
                currVal += memo(i+1,j1 + a, j2 + b, grid, dp);
                maxVal =  max(maxVal,currVal) ;
            }
        }
        return dp[i][j1][j2] = maxVal ;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //dp[m][n][n] 
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1e9)));

        return memo(0,0,n-1,grid,dp);
    }
};