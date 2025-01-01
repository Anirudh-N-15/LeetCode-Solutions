class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(days.begin(),days.end());
        vector<int> dp(366,0);

        for(int i=1;i<366;++i){
            if(travel.count(i) == 0 ){
                dp[i] = dp[i-1];
            }
            else{
                int pass1 = dp[i-1] + costs[0];
                int pass7 = dp[max(0,i-7)] + costs[1];
                int pass30 = dp[max(0,i-30)] + costs[2];

                dp[i] = min({pass1,pass7,pass30});
            }
        }
        return dp[365];
    }
};