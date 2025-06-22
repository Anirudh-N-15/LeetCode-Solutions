class Solution {
public:
    int minCoins(vector<int>& coins, vector<vector<int>>& dp,int i, int amount) {
        if(amount == 0) {
            return 0;
        }
        if(i == 0) return 1e9 ;
        if(dp[i][amount] != -1) {
            return dp[i][amount] ;
        }

        if(coins[i -1 ] <= amount) {
            int take = 1 + minCoins(coins,dp,i,amount - coins[i-1]);
            int notTake = minCoins(coins,dp,i-1,amount);

            return dp[i][amount] = min(take,notTake);
        } else {
            return dp[i][amount] = minCoins(coins,dp,i-1,amount);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        int result = minCoins(coins, dp, n, amount);
        return (result >= 1e9) ? -1 : result ;
    }
};