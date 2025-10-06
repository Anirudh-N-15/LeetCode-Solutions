class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        using t = tuple<int,int,int> ;
        priority_queue<t,vector<t>,greater<t>> pq ;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        vector<vector<int>> time(n,vector<int>(n,1e6));
        pq.push({grid[0][0],0,0});

        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

        while(!pq.empty()) {
            auto [currTime, row, col] = pq.top();
            pq.pop() ;

            if(row == n-1 && col == n-1) {
                return currTime ;
            }

            for(auto &dir : dirs) {
                int nrow = row + dir.first ;
                int ncol = col + dir.second ;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol]) {
                    int newTime = max(currTime,grid[nrow][ncol]);

                    if(newTime < time[nrow][ncol]) {
                        time[nrow][ncol] = newTime ;
                        vis[nrow][ncol] = true ;
                        pq.push({newTime,nrow,ncol});
                    }
                }
            }
        }
        return -1 ;
    }
};