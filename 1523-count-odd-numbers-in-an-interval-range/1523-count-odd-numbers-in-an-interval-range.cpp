class Solution {
public:
    int countOdds(int low, int high) {
        if(high == low && low % 2 == 0) return 0;
        if(high == low && low % 2 != 0) return 1;

        if(high % 2 == 0) high-- ;

        return (high - low)/2 +1;
    }
};