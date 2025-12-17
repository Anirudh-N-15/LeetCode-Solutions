//The states are profit, k and the current state of transaction(i.e going on or not)

class Solution {
public:
    int memo(vector<int>& prices,vector<vector<vector<int>>>& dp,int k,int currState,int i) {
        int n = prices.size() ;
        if(i >= n) return 0; 

        if(dp[i][k][currState] != -1) return dp[i][k][currState] ;

        int profit = 0;
        //This aims to skip the current price and go to the next one 
        profit = max(profit, memo(prices,dp,k,currState,i+1));

        if(currState) {
            //Currently engaged in a transaction and we wish to sell our current stock
            profit = max(profit, memo(prices,dp,k-1,0,i+1) + prices[i]) ;
        } else if(k > 0){
            //Currently started a transation and we have bought the current stock
            profit = max(profit, memo(prices,dp,k,1,i+1) - prices[i]) ;
        }

        return dp[i][k][currState] = profit ;
    }


    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));

        return memo(prices,dp,k,0,0) ;
    }
};