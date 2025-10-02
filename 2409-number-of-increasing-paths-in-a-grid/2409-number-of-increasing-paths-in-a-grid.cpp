class Solution {
public:
    const int mod = 1e9 + 7 ;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col) {
        int m = grid.size(), n = grid[0].size() ;

        if(dp[row][col] != -1) {
            return dp[row][col] ;
        }

        int total = 0 ;
        for(auto &dir : dirs) {
            int nrow = row + dir.first ;
            int ncol = col + dir.second ;

            if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] > grid[row][col]) {
                total = (total + dfs(grid,dp,nrow,ncol) % mod) % mod ;
            }
        }

        dp[row][col] = (1 + total)% mod ;
        return dp[row][col] ;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(dp[i][j] == -1) {
                    ans = (ans + dfs(grid,dp,i,j) % mod) %  mod ;
                } else {
                    ans = (ans + dp[i][j] % mod) % mod ;
                }
            }
        }
        return ans ;
    }
};