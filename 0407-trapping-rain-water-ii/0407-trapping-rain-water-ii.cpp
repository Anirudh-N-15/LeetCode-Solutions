class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int ans = 0;
        int m = height.size(), n = height[0].size() ;
        using t = tuple<int,int,int> ;
        priority_queue<t,vector<t>, greater<t>> pq ;
        vector<vector<bool>> vis(m,vector<bool>(n,0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    vis[i][j] = true ;
                    pq.push({height[i][j], i, j});
                }
            }
        }

        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!pq.empty()) {
            auto [currHeight, currRow, currCol] = pq.top() ;
            pq.pop() ;

            for(auto dir : dirs) {
                int nRow = currRow + dir.first ;
                int nCol = currCol + dir.second ;

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n) {
                    if(!vis[nRow][nCol]) {
                        vis[nRow][nCol] = true ;
                        ans += max(0, currHeight - height[nRow][nCol]) ;
                        int newHeight = max(currHeight, height[nRow][nCol]) ;
                        pq.push({newHeight,nRow,nCol});
                    }
                }
            }
        }
        return ans ;
    }
};