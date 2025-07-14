class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) return dp[i][j] ;
        int m = matrix.size(), n = matrix[0].size() ;
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

        int count = 1;
        for(auto dir : dirs) {
            int nrow = dir.first + i;
            int ncol = dir.second + j;

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                if(matrix[nrow][ncol] > matrix[i][j]){
                    count = max(count,1+dfs(nrow,ncol,matrix,dp));
                }
            }   
        }
        return dp[i][j] = count ;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size() ;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = 1;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans = max(ans,dfs(i,j,matrix,dp));
                
            }
        }
        return ans ;
    }
};