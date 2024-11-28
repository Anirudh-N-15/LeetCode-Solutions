class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshCount = 0;
        queue<pair<int,int>> rottenQ;

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]==2){
                    rottenQ.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshCount++ ;
                }
            }
        }

        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int minutes = 0;

        while(!rottenQ.empty() && freshCount > 0){
            int size = rottenQ.size();

            for(int i=0;i<size;++i){
                auto [x,y] = rottenQ.front();
                rottenQ.pop();

                for(auto [dx,dy] : directions){
                    int newrow = x + dx ;
                    int newcol = y + dy ;

                    if(newrow >=0 && newrow<rows && newcol >=0 && newcol<cols && grid[newrow][newcol]==1){
                        grid[newrow][newcol] = 2 ;
                        freshCount-- ;
                        rottenQ.push({newrow,newcol});
                    }
                }
            }
            minutes++ ;
        }

        return freshCount==0 ? minutes : -1 ;

    }
};