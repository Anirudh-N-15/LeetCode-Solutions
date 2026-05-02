class Solution {
public:
    int rotatedDigits(int n) {
        vector<bool> dp(10, false);
        dp[2] = dp[5] = dp[6] = dp[9] = true;
        int count = 0;

        for (int i = 0; i <= n; i++) {
            int num = i ;
            bool flag = false ;
            while(num > 0) {
                int currNum = num % 10;
                if(currNum == 3 || currNum == 4 || currNum == 7) {
                    flag = true ;
                }
                num /= 10 ;
            }
            if(flag) {
                continue ;
            } else {
                num = i ;
                while(num > 0) {
                    int currNum = num % 10 ;
                    
                    if(dp[currNum]) {
                        count++ ;
                        break;
                    }
                    num /= 10 ;
                }
            }
        }
        return count ;
    }
};