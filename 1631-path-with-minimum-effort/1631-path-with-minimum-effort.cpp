//Route's effort is max. absolute diff in heights b/w 2 consecutive.
//We apply dijkstra's algorithm

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        using T = tuple<int,int,int> ;
        priority_queue<T,vector<T>, greater<>> pq ;
        pq.push({0,0,0});
        dist[0][0] = 0;
        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{0,1},{1,0}};

        while(!pq.empty()) {
            auto [orgDist, row, col] = pq.top();
            pq.pop();

            for(auto dir : dirs) {
                int nrow = row + dir.first ;
                int ncol = col + dir.second ;

                if(row == m-1 && col == n-1){
                    return orgDist ;
                }

                if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n) {
                    int newDist = max(abs(heights[row][col] - heights[nrow][ncol]),orgDist);
                    if(newDist < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newDist ;
                        pq.push({newDist,nrow,ncol});
                    }
                }
            }
        }
        return -1;
    }
};