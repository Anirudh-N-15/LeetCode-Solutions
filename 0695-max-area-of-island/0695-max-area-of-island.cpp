class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int& row, int& col,int& area){
        int m= grid.size(), n = grid[0].size();
        vis[row][col] = 1;
        area++ ;
        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};

        for(auto &dir : dirs) {
            int nrow = row + dir.first, ncol = col + dir.second ;

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                if(!vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    dfs(grid,vis,nrow,ncol,area);
                }
            }
        }
        return area ;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size() ;
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        int ans = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    area = dfs(grid,vis,i,j,area);
                    ans = max(ans,area);
                }
            }
        }
        return ans ;
    }
};