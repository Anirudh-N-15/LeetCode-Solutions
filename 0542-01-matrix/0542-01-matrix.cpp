class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0)); //visited matrix
        vector<vector<int>> ans(m,vector<int>(n,0)); //to return ans
        queue<pair<pair<int,int>,int>> q; //keep track of row&col of 0 and dist to 1
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}}; //all 4 dirs to iterate

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i,j},0}); //multi-source bfs ready(row,col),dist
                }
            }
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(auto it : dir) {
                int nrow = node.first.first + it.first ;
                int ncol = node.first.second + it.second ;
                int dist = node.second;

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                    visited[nrow][ncol] =1;
                    ans[nrow][ncol] = dist + 1;
                    q.push({{nrow,ncol},dist + 1});
                }
            }
        }
        return ans ;
        
    }
};
//The intuition is to do a multi-source BFS and keep a visited matrix(not a visited array)
//Push all the 0s into the queue and then process it

