class Solution {
public:
    bool check(vector<vector<int>>& grid,int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // check left
        for (int j = c - 1; j >= 0; j--) {
            if (grid[r][j] != 0) return false;
        }

        // check right
        for (int j = c + 1; j < cols; j++) {
            if (grid[r][j] != 0) return false;
        }

        // check up
        for (int i = r - 1; i >= 0; i--) {
            if (grid[i][c] != 0) return false;
        }

        // check down
        for (int i = r + 1; i < rows; i++) {
            if (grid[i][c] != 0) return false;
        }

        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size() ;
        int count = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 1 && check(mat,i,j)) {
                    count++ ;
                }
            }
        } 
        return count ;
    }
};