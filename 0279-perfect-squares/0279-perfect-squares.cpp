class Solution {
public:
    int memo(int i,vector<int>& squares,int n,vector<vector<int>>& dp) {
        if(i == squares.size()) {
            if(n == 0){
                return 0;
            }
            return 1e6;
        }
        if(dp[i][n] != -1) {
            return dp[i][n] ;
        }

        int take = 1e6, notTake = 1e6;
        if(squares[i] <= n) {
            take = 1 + memo(i,squares,n - squares[i],dp);
            notTake = memo(i+1,squares,n,dp);
        } else {
            notTake = memo(i+1,squares,n,dp);
        }
        return dp[i][n] = min(take,notTake);
    }

    int numSquares(int n) {
        vector<int> squares(101,0);
        for(int i=1;i<=100;i++) {
            squares[i] = i*i ;
        }
        vector<vector<int>> dp(101,vector<int>(n+1,-1));
        return memo(1,squares,n,dp);
    }
};