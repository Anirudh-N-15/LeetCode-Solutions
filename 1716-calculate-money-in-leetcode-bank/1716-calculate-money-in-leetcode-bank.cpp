class Solution {
public:
    int totalMoney(int n) {
        int counter = 1;
        int count = 1;
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(i%7 == 0) {
                ans += count ;
                count++ ;

                counter++ ;
                count = counter ;
            } else {
                ans += count ;
                count++ ;
            }
        }
        return ans   ;
    }
};