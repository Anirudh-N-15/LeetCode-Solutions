class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count =0 ;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n-1; ++j) {
                if(grid[j][i] >= grid[j+1][i]){
                   count +=  grid[j][i]- grid[j+1][i] +1 ;
                   grid[j+1][i] += grid[j][i] - grid[j+1][i] + 1;   
                }
                cout << count << " " ;
            }
        }
        return count ;
    }
};