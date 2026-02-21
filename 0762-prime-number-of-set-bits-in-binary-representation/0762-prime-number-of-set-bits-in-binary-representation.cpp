class Solution {
public:
    bool isPrime(int n) {
        if(n == 1 || n == 0) return false ;
        if(n == 2) return true ;

        for(int i=2; i*i <= n; i++) {
            if(n % i == 0) {
                return false ;
            }
        }
        return true ;
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0 ;

        for(int i=left;i<=right;i++) {
            cout << __builtin_popcount(i) << endl ;
            if(isPrime(__builtin_popcount(i))) {
                count++ ;
            }
        }
        return count ;
    }
};