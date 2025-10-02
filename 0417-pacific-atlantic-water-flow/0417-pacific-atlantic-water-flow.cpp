class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size() ;
        vector<vector<bool>> pacific(m,vector<bool>(n,0)) ;
        vector<vector<bool>> atlantic(m,vector<bool>(n,0)) ;
        queue<pair<int,int>> q1 ;
        queue<pair<int,int>> q2 ;

        vector<vector<int>> ans ;

        for(int i=0;i<n;i++) {
            q1.push({0,i});
            pacific[0][i] = 1;
        }
        for(int i=0;i<m;i++) {
            q1.push({i,0});
            pacific[i][0] = 1;
        }
        for(int i=0;i<m;i++) {
            q2.push({i,n-1});
            atlantic[i][n-1] = 1;
        }
        for(int i=0;i<n;i++) {
            q2.push({m-1,i});
            atlantic[m-1][i] = 1;
        }

        bfs(heights,q1,pacific);
        bfs(heights,q2,atlantic);

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j}) ;
                }
            }
        }

        return ans ;
    }
    void bfs(vector<vector<int>>& heights,queue<pair<int,int>>& q,vector<vector<bool>> &vis) {
        int m = heights.size(), n = heights[0].size() ;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}}; 

        while(!q.empty()) {
            auto [row,col] = q.front() ;
            q.pop();

            for(auto dir : dirs) {
                int nrow = row + dir.first ;
                int ncol = col + dir.second ;

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    if(heights[nrow][ncol] >= heights[row][col] && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = true ;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }

};