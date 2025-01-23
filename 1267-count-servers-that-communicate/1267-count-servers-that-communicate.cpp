class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        vector<int> rowcount(m,0); vector<int> colcount(n,0) ;
        int ans = 0;

        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(grid[i][j] == 1) {
                    rowcount[j]++ ;
                    colcount[i]++ ;
                }
            }
        }

        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(grid[i][j] == 1 && (rowcount[j] > 1 || colcount[i] > 1)) {
                    ans++ ;
                }
            }
        }
        return ans ;

    }
};