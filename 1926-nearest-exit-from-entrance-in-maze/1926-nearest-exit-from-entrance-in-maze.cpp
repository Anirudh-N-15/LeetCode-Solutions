class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size() ;
        int ans = INT_MAX;
        using t = tuple<int,int,int> ;
        queue<t> q;
        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        int row = entrance[0], col = entrance[1] ;
        maze[row][col] = '+' ;

        q.push({row,col,0});
        while(!q.empty()) {
            auto [currRow, currCol, moves] = q.front();
            q.pop();
    
            for(auto dir : dirs) {
                int nrow = dir.first + currRow ;
                int ncol = dir.second + currCol ;

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && maze[nrow][ncol] == '.') {
                    if(nrow == 0 || nrow == m -1 || ncol == 0 || ncol == n -1) {
                        return moves + 1;
                    }
                    maze[nrow][ncol] = '+' ;
                    q.push({nrow,ncol,moves+1});
                }
            }
        } 
        return -1 ;
    }
};