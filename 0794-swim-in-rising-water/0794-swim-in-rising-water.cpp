class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 1e6 ;
        using T = tuple<int,int,int> ;
        priority_queue<T,vector<T>,greater<>> pq ;
        vector<vector<int>> dist(n,vector<int>(n,1e6));
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        
        dist[0][0] = grid[0][0] ;
        pq.push({grid[0][0],0,0});

        while(!pq.empty()) {
            auto [orgTime, row, col] = pq.top();
            pq.pop();

            for(auto dir : dirs) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if(row == n -1 && col == n-1){
                return orgTime ;
                }

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n) {
                    int newTime = max(grid[nrow][ncol], orgTime);

                    if(newTime < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newTime ;
                        pq.push({newTime,nrow,ncol});
                    }
                }
            }
        }
        return -1 ;

    }
};