//Apply the same logic as question no.130
//The idea here is to again traverse only the borders and perform a dfs from there.
//Mark all the cells performed from that border cell
//Finally count all the cells in the center

class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& marked,int row,int col) {
        int m = grid.size(), n = grid[0].size();
        marked[row][col] = 1;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        for(auto it : dir) {
            int nrow = row + it.first ;
            int ncol = col + it.second ;
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                if(grid[nrow][ncol] == 1 && !marked[nrow][ncol]) {
                    dfs(grid,marked,nrow,ncol);
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> marked(m,vector<bool>(n,0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    if(grid[i][j] != 0) dfs(grid,marked,i,j);
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!marked[i][j] && grid[i][j] == 1) {
                    ans++ ;
                }
            }
        }
        return ans ;
    }
};