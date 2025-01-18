class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<array<int, 2>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> cost (m, vector<int>(n,INT_MAX));
        cost[0][0] = 0;

        deque<array<int, 3>> dq; //0-cost moves to front and 1-cost moves to back
        dq.push_back({0,0,0}); //row,col,cost

        while(!dq.empty()) {
            auto [x,y,curCost] = dq.front();
            dq.pop_front();

            if(x == m-1 && y == n-1) return curCost ;

            for(int i=0; i<4; ++i) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];

                if(nx >= 0 && nx < m && ny >=0 && ny < n) {
                    int newCost = curCost + (grid[x][y] != i + 1);

                    if(newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost ;

                        if(grid[x][y] == i+1) {
                            dq.push_front({nx, ny, newCost});
                        }
                        else {
                            dq.push_back({nx,ny,newCost});
                        }
                    }
                }
            }
        }
        return -1 ;
    }
};