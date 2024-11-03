class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target > x + y) return false ;
        if(x== target || y==target || x+y==target) return true ;
        return ((target % gcd(x,y) )== 0) ;
    }
};