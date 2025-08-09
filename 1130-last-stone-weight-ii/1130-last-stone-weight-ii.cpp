//Initialise the value with sum of stones  + 3000. Since its range can go beyond less 
//than 0 upto -3000.

class Solution {
public:
    int memo(vector<int>& stones,int i, int val, vector<vector<int>>& dp) {
        int n = stones.size();
        if(i == n) {
            if(val < 0) {
                return 1e9 ;
            }
            return 0 ;
        }
        if(dp[i][val + 3000] != -1) {
            return dp[i][val + 3000] ;
        }

        int pos = stones[i] + memo(stones,i+1,val + stones[i],dp);
        int neg = -stones[i] + memo(stones,i+1,val - stones[i],dp);

        return dp[i][val + 3000] = min(pos,neg) ;
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n+1,vector<int>(6000,-1));

        return memo(stones,0,0,dp);
    }
};