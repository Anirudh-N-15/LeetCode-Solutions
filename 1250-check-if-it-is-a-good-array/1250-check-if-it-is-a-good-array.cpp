class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcdVal = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            gcdVal = gcd(gcdVal,nums[i]);
        }
        return gcdVal == 1 ? true : false ;
    }
};