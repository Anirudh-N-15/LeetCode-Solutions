// Sn = (n/2)(2a + (n-1)d)

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = (n)*((2 + (n-1)*2)/2) ;
        int sumEven = (n)*((4 + (n-1)*2)/2) ;

        int ans = gcd(sumOdd,sumEven) ;
        return ans ;
    }
};