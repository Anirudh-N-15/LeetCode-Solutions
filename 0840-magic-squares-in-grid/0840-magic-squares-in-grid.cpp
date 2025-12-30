class Solution {
public:
    bool solve(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[row + 1][col + 1] != 5)
            return false;
        unordered_set<int> uset;

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9)
                    continue;
                uset.insert(grid[i][j]);
            }
        }

        if (uset.size() != 9)
            return false;

        int sum = 15;

        for (int i = 0; i < 3; i++) {
            if (grid[row + i][col] + grid[row + i][col + 1] +
                    grid[row + i][col + 2] !=
                sum)
                return false;
        }

        for (int j = 0; j < 3; j++)
            if (grid[row][col + j] + grid[row + 1][col + j] +
                    grid[row + 2][col + j] !=
                sum)
                return false;

        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] !=
            sum)
            return false;

        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] !=
            sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int colSize = grid.size(), rowSize = grid[0].size();
        int count = 0;
        for (int i = 0; i < colSize; i++) {
            for (int j = 0; j < rowSize; j++) {
                if(i+2 < colSize && j+2 < rowSize) {
                    if (solve(i, j, grid)) {
                        count++;
                    }
                }
                
            }
        }
        return count;
    }
};