class Solution {
public:
    int smallestNumber(int n) {
        int ans = n ;

        for(int i=1;i<=n;i++) {
            if(pow(2,i) > n) {
                ans = pow(2,i);
                break ;
            }
        }
        return ans - 1;
    }
};