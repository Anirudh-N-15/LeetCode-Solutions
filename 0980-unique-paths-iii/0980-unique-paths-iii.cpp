//So this question is similar to dfs approaches with a small twist that you should mark the
//cells you have visited and then after completing that dfs call just unmark them.

//We can mark the grid by marking the grid itself using -1.

class Solution {
public:
    int n, m;
    int dfs(int i, int j, pair<int,int> dest , int cellsLeft,vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        if(cellsLeft == -1 && i==dest.first && j==dest.second) {
            return 1; //Means we have succesfully reached our dest by traversing the 
                      //whole grid which is indicated by 0 cells left
        }

        grid[i][j] = -1 ;
        int ans = 0;

        for(auto dir : dirs) {
            int nrow = i + dir.first, ncol = j + dir.second;

            if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && grid[nrow][ncol] != -1) {
                ans += dfs(nrow,ncol,dest,cellsLeft-1,grid);
            }
        }
        grid[i][j] = 0;

        return ans ;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int emptyCells = 0;
        pair<int,int> src, dest;

        for(int i=0;i<m;i++) {
            for(int j =0;j<n;j++) {
                if(grid[i][j] == 0) {
                    emptyCells++ ;
                } else if(grid[i][j] == 1){
                    src = {i,j} ;
                } else if(grid[i][j] == 2) {
                    dest = {i,j};
                }
            }
        }

        return dfs(src.first, src.second, dest, emptyCells, grid);
    }
};