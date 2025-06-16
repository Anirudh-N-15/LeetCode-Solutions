class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int freshCount = 0, minutes = 0;
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    freshCount++ ;
                } else if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty() && freshCount > 0) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                auto rotten = q.front();
                q.pop();

                for(auto it : dir) {
                    int nrow = rotten.first + it.first ;
                    int ncol = rotten.second + it.second ;

                    if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                        freshCount-- ;
                    }
                }
            }
            minutes++ ;
        }
        return freshCount == 0 ? minutes : -1 ;
    }
};