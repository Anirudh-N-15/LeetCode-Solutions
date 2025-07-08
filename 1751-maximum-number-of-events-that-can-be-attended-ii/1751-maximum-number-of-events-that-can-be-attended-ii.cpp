class Solution {
public:
    int memo(int pos, vector<vector<int>>& events,int k,int n, vector<vector<int>>& dp){
        int i;

        if(pos >= n || k == 0){ 
            return 0;
        }

        if(dp[pos][k] != -1){
            return dp[pos][k] ;
        }

        for(i=pos + 1;i<n;i++) {
            if(events[i][0] > events[pos][1]) {
                break;
            }
        }
        return dp[pos][k] = max(memo(pos+1,events,k,n,dp), events[pos][2] + memo(i,events,k-1,n,dp));
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));

        return memo(0,events,k,n,dp);
    }
};