class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0 || n == 2) return 1 ;
        if(n == 1) return 0 ;
        int num = 2;
        for(int i=0;i<32;i++) {
            if(num < n) num = pow(2,i) - 1  ;
            else break ;
        }
        return num - n ;
    }
};