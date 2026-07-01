class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        using t = tuple<int,int,int> ;

        int m = grid.size(), n = grid[0].size() ;
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q ;
        priority_queue<t,vector<t>> pq;

        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<int>> best(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j< n ;j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
                
            }
        }

        while(!q.empty()) {
            auto node = q.front() ;
            q.pop() ;

            for( const auto &dir : dirs) {
                int u = node.first + dir[0] ;
                int v = node.second + dir[1] ;

                if(u < m && v < n && u >=0 && v >= 0 && dist[u][v] == INT_MAX) {
                    dist[u][v] = dist[node.first][node.second] + 1;
                    q.push({u,v});
                }
            }
        }

        pq.push({dist[0][0],0,0});
        best[0][0] = dist[0][0];

        while(!pq.empty()) {
            auto [safety,u,v] = pq.top() ;
            pq.pop() ;

            if(u == m-1 && v == n-1) {
                return safety ;
            }

            for(const auto &dir : dirs) {
                int nu = u + dir[0] ;
                int nv = v + dir[1] ;

                if(nu < m && nv < n && nu >= 0 && nv >= 0 ) {
                    int newSafe = min(safety,dist[nu][nv]);

                    if(newSafe > best[nu][nv]) {
                        best[nu][nv] = newSafe ;
                        pq.push({newSafe,nu,nv});
                    }
                }
            }
        }
        return 0 ;
    }
};