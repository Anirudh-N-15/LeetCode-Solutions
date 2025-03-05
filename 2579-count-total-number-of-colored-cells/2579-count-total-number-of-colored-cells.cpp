class Solution {
public:
    long long coloredCells(int n) {
        
        long long ans = 1;
        int comDiff = 4 ;

        for(int i=1;i<n;++i){
            ans = ans + i*comDiff ;
        }
        return ans ;

    }
};