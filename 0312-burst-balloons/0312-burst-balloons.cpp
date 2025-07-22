class Solution {
public:
    const int mod = 1e9 + 7;

    int memo(int i,int j, vector<int>& nums,vector<vector<int>>& dp) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j] ;
        }

        int maxi = -1e7 ;
        for(int index = i;index<=j;index++) {
            int cost = ((nums[i-1]*nums[index]*nums[j+1])%mod + 
                       (memo(i,index-1,nums,dp) + memo(index+1,j,nums,dp))%mod)%mod;
            maxi = max(maxi,cost);            
        }
        return dp[i][j] = maxi ;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return memo(1,n,nums,dp);
    }
};