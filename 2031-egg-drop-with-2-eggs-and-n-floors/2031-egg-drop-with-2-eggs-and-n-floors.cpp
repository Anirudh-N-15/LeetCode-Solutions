// To solve this we have to find the minimum n for which the equation = 
// n + n-1 + n-2 + n-3 + ... + 1 >= floors
// is satisfied.
// That is at every interval we should decrease the number of floors by 1, and 
// also find the minimum floor to start with. 

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int eggs, int floors) {
        if (floors == 0 || floors == 1) return floors;
        if (eggs == 1) return floors;

        if(dp[eggs][floors] != -1) {
            return dp[eggs][floors] ;
        }

        int ans = INT_MAX ;
        for(int k=1;k<=floors;k++) {
            int breaks = solve(eggs-1,k -1);        //egg breaks
            int survives = solve(eggs, floors - k); //egg survives
            int worst = 1 + max(breaks,survives);
            ans = min(ans,worst); 
        }
        return dp[eggs][floors] =  ans ;
    }

    int twoEggDrop(int n) {
        dp.assign(3, vector<int>(n + 1, -1)); //eggs =2, but index =2
        return solve(2, n);
    }
};