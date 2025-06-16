class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>> &visited,int row,int col){
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
        queue<pair<int,int>> q;

        visited[row][col] = 1;
        q.push({row,col});

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(auto it : dir) {
                int nrow = node.first + it.first ;
                int ncol = node.second + it.second ;

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    if(!visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!visited[i][j] && grid[i][j] != '0') {
                    count++ ;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return count ;
    }
};