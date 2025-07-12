class Solution {
public:
    // int memo(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n) {
    //     if(i == n-1) return triangle[i][j] ;

    //     if(dp[i][j] != -1){
    //         return dp[i][j] ;
    //     }
        
    //     int bottom = triangle[i][j] + memo(i+1,j,triangle,dp,n);
    //     int left = triangle[i][j] + memo(i+1,j+1,triangle,dp,n);

    //     return dp[i][j] =  min(bottom,left);
    // }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));

        for(int j=0;j<triangle[n-1].size();j++) {
            dp[n-1][j] = triangle[n-1][j] ;
        }

        for(int i=n-2;i>=0;i--) {
            for(int j=i;j>=0;j--) {
                int downVal = triangle[i][j] + dp[i+1][j] ;
                int leftVal = triangle[i][j] + dp[i+1][j+1]; 
                dp[i][j] = min(downVal,leftVal);
            }
        }

        return dp[0][0] ;
        //return memo(0,0,triangle,dp,n);
    }
};