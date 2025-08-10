class Solution {
public:
    int dp[102][102][102] ;//k,i,j
    int mod = 1e9 + 7;
    int memo(vector<int>& group, vector<int>& profit,int k,int i, int j,int n, int minProfit) {
        if(k == profit.size()) {
            if(j >= minProfit && i <= n) {
                return 1;
            }
            return 0 ;
        } else if(i > n) {
            return 0; 
        }
        if(dp[k][i][j] != -1) return dp[k][i][j] ;

        int take = 0, notTake = 0;
        take = memo(group,profit,k+1,i+group[k],min(j + profit[k],minProfit),n,minProfit);
        notTake = memo(group,profit,k+1,i,j,n,minProfit);

        return dp[k][i][j] = (take % mod + notTake % mod) % mod ;
    }


    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return memo(group,profit,0,0,0,n,minProfit);
    }
};