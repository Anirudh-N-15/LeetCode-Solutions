class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1 ;

        vector<pair<int,int>> possibledirections = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

        queue<pair<int,int>> q ;
        q.push({0,0});
        grid[0][0] = 1;

        while(!q.empty()){
            pair<int,int> currentcord = q.front();
            q.pop();

            int row = currentcord.first ;
            int col = currentcord.second ;
            int dist = grid[row][col] ;

            if(row==n-1 && col ==n-1){
                return dist ;
            }

            for(auto dir : possibledirections){
                int dr = dir.first;
                int dc = dir.second;
                int nr = row + dr ;
                int nc = col + dc ;

                if(nr >= 0 && nr <n && nc >=0 && nc <n && !grid[nr][nc]){
                    q.push({nr,nc});
                    grid[nr][nc] = dist + 1;
                }
            }
        }
        return -1 ;
    }
};