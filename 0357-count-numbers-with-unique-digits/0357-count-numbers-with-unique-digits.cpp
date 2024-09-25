class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
          return 1 ;  
        } 

        int dp[n+1];
        dp[0]=1;
        dp[1]=10;
        int fact[10];
        fact[0]=1;

        for(int i=1;i<10;++i){
            fact[i] = i * fact[i-1];
        }

        for(int i=2;i<=n;++i){
            dp[i] = dp[i-1] + 9 * fact[9]/fact[9-i+1];
        }
        return dp[n] ;
    }
};