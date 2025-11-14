class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1,vector<int>(n+1,0));

        for(const auto &query : queries) {
            int r1 = query[0], c1 = query[1], r2 = query[2], c2 = query[3] ;

            diff[r1][c1]++ ;
            diff[r1][c2+1]-- ;
            diff[r2+1][c1]-- ;
            diff[r2+1][c2+1]++ ;
        }

        vector<vector<int>> ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int top = (i > 0) ? diff[i-1][j] : 0;
                int left = (j > 0) ? diff[i][j-1] : 0;
                int diag = (i>0 && j>0) ? diff[i-1][j-1] : 0;

                diff[i][j] =  diff[i][j] + top + left - diag ;
                ans[i][j] = diff[i][j] ;
            }
        }
        return ans ;
    }
};