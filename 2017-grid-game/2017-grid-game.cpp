class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowPoints = accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long secondRowPoints = 0, secondRobotPoints = LLONG_MAX, n = grid[0].size() ;

        for(long long i=0;i<n;++i) {
            firstRowPoints -= grid[0][i] ;
            secondRobotPoints = min(secondRobotPoints,max(firstRowPoints,secondRowPoints));
            secondRowPoints += grid[1][i] ;
        }
        return secondRobotPoints ;
    }
};