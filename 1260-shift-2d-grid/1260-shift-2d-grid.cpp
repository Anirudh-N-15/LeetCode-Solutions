class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size() ;
        vector<int> shift(m*n);
        vector<vector<int>> ans(m,vector<int>(n));

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++ ) {
                shift[count++] = grid[i][j] ;
            }
        }

        k = k % (m * n) ;

        reverse(shift.begin(),shift.end());
        reverse(shift.begin(),shift.begin() + k);
        reverse(shift.begin()+(k),shift.end());

        count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = shift[count++] ;
            }
        }
        return ans ;
    }
};