class Solution {
public:
    bool dfs(vector<vector<char>>& grid,int i, int j,int pi,int pj,vector<vector<bool>>& visited) {
        visited[i][j] = true;
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

        for (auto &dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;

            if (grid[ni][nj] != grid[i][j])
                continue;

            if (!visited[ni][nj]) {
                if (dfs(grid, ni, nj, i, j, visited))
                    return true;
            }

            else if (ni != pi || nj != pj) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        vector<vector<bool>> visited(n,vector<bool>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j]) {
                    if(dfs(grid,i,j,-1,-1,visited)) {
                        return true ;
                    }
                }
            }
        }

        return false ;
    }
};