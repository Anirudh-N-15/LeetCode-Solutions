class Solution {
public:
    int f1(int n, vector<int>& nums, vector<vector<int>>& dp1) {
        if(n < 0) return 0;
        if(n == 0) return nums[0];

        if(dp1[n][n] != -1) return dp1[n][n] ;

        return dp1[n][n] = max(f1(n-1,nums,dp1),nums[n] + f1(n-2,nums,dp1));
    }  

    int f2(int n, vector<int>& nums, vector<vector<int>>& dp2) {
        if(n == 0) return 0;
        if(n == 1) return nums[1];

        if(dp2[n][n] != -1) return dp2[n][n] ;

        return dp2[n][n] = max(f2(n-1,nums,dp2),nums[n] + f2(n-2,nums,dp2));
    } 

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<vector<int>> dp1(n,vector<int>(n,-1));
        vector<vector<int>> dp2(n,vector<int>(n,-1));
        
        return max(f1(n-2,nums,dp1),f2(n-1,nums,dp2));
    }
};