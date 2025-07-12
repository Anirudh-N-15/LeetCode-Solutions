// We will be storing the answers in a 2d grid, for every index there are three
// possibilities that is left,bottom and right. So we will be using recursion
// to solve for those and find the minimum sum.

// Note:A greedy approach won't work here because the last value can be some
// big number and hence our answer could go wrong. Therefore just try all paths.

// Small tip : Initialise dp array with very big value = 1e9

class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        if (j < 0 || j >= n)
            return 1e9;

        if (i == n - 1)
            return matrix[i][j];

        if (dp[i][j] != 1e9)
            return dp[i][j];

        int left =  memo(i + 1, j - 1, matrix, dp);
        int down =  memo(i + 1, j, matrix, dp);
        int right = memo(i + 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));

        int ans = 1e9 ;

        for(int i=0;i<n;i++) {
            ans = min(ans,memo(0,i,matrix,dp));
        }

        return ans;
    }
};