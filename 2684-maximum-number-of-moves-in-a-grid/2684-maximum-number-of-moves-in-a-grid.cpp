class Solution {
public:

    bool checkboundary(int i,int j,int n,int m){
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<int>> dp(n,vector<int>(m,0));

        vector<pair<int,int>> dir = {{1,1},{0,1},{-1,1}};

        for(int col = m-2;col >=0;col--){
            for(int row = n-1;row>=0;row--){
                for(int i=0;i<=2;++i){
                    int newrow = row + dir[i].first ;
                    int newcol = col + dir[i].second ;

                    if(checkboundary(newrow,newcol,n,m) && grid[newrow][newcol] > grid[row][col]){
                        dp[row][col] = max(dp[row][col], dp[newrow][newcol] + 1);
                    }
                }
            }
        }
        int result = 0 ;
        for(int i=0;i<n;++i){
            result = max(result,dp[i][0]);
        }
        return result ;
    }
};