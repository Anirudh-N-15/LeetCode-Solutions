class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //Here acc to the choice diagram we can either choose an element or avoid it.
        //If the element in nums <= sum, then we can either include it or not.
        //That is what the or condition is for. The choice we make will check the prev
        //one and if any one is true the dp[i][j] = true 

        int sum = 0;
        for(const int &num : nums) {
            sum += num;
        }
        int n = nums.size();
        if(sum % 2 != 0) return false ;

        sum /= 2; // We only need half of the sum 
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));

        for(int i=0;i<=n;i++) {
            dp[i][0] = true ;   //We can make 0 sum using 0-n elements in nums
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=sum;j++) {
                //The choice we are currently making is less than sum
                //or not. We are solving the subproblems.
                if(nums[i-1] <= j) { 
                    dp[i][j] = dp[i - 1][j - nums[i -1]] || dp[i- 1][j] ;                
                } else {
                    dp[i][j] = dp[i - 1][j] ;
                }
            }
        }
        return dp[n][sum] ;
    }
};