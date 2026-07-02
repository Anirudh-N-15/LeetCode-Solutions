class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        using t = tuple<int,int,int> ;
        int m = grid.size(), n = grid[0].size() ;
        vector<vector<int>> best(m,vector<int>(n,-1));
        best[0][0] = health - grid[0][0] ;

        queue<t> q ;
        q.push({best[0][0],0,0});
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()) {
            auto [currHealth,row,col] = q.front() ;
            q.pop() ;

            for(const auto &dir : dirs ) {
                int nrow = row + dir[0] ;
                int ncol = col + dir[1] ;

                if( nrow < m && nrow >= 0 && ncol < n && ncol >= 0) {
                    if(currHealth - grid[nrow][ncol] > best[nrow][ncol]) {
                        best[nrow][ncol] = currHealth - grid[nrow][ncol] ;
                        q.push({best[nrow][ncol],nrow,ncol});
                    }
                }
            }
        }

        return best[m-1][n-1] >= 1 ? true : false ;
    }
};