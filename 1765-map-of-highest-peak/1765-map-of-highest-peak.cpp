class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size() ;
        vector<vector<int>> height(m,vector<int>(n,-1));
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q ;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    height[i][j] = 0 ;
                }
            }
        }

        while(!q.empty()) {
            auto dirs = q.front();
            q.pop();
            int row = dirs.first, col = dirs.second ;

            for(int i=0;i<4;++i) {
                int nrow = row + dir[i].first , ncol = col + dir[i].second ;

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && height[nrow][ncol] == -1){
                    height[nrow][ncol] = height[row][col] +1 ;
                    q.push({nrow,ncol});
                }
            }
        }
        return height ;
    }
};