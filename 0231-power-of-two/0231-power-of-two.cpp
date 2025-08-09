class Solution {
public:
    bool isPowerOfTwo(int n) {
        //Simple trick is to check if n&(n-1) == 0. This works since n is a power of 2
        //its set bit will be like 10000... and n-1 will be like 0111...
        //Since you bitwise and it you will get 0 as the answer else it is not a power
        // of 2.
        if(n <= 0 ) return false ;
        return (n&(n-1)) == 0 ? true : false ;
    }
};