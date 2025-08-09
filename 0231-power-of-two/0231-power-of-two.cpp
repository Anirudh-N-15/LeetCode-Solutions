class Solution {
public:
    bool isPowerOfTwo(int n) {
        vector<long long > powers(33,1);
        if(n == 1) return true ;
        int i;
        for(i=1;i<32;i++) {
            powers[i] = powers[i-1] * 2 ;
            if(powers[i] == n) {
                return true ;
            }
        }
        return false ;
    }
};