//The leftmost bit is the msb. So it makes sense to flip the first number if it is zero.
//Take the count of zeroes in each column. If zeroCount > oneCount then toggle that column.


class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) {
            if(grid[i][0] == 0) {
                for(int j=0;j<m;j++) {
                    grid[i][j] = !grid[i][j] ;
                }
            }
        }

        for(int j=0;j<m;j++) {
            int zeroCount = 0, oneCount = 0;
            for(int i=0;i<n;i++) {
                if(grid[i][j] == 0) {
                    zeroCount++ ;
                } else {
                    oneCount++ ;
                }
            }
            if(zeroCount > oneCount) {
                for(int i=0;i<n;i++) {
                    grid[i][j] = !grid[i][j] ;
                }
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++) {
            int count = 0;
            for(int j=m-1;j>=0;j--) {
                ans += grid[i][j]!=0 ? pow(2,count) : 0;
                count++ ;
            }
        }
        return ans ;
    }
};