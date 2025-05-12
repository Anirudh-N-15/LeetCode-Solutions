class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX ;

        for(const int &num : nums) {
            if(num > second) {
                return true ;
            } else if(num <= second && num > first) {
                second = num ;
            } else if(num <= first){
                first = num ;
            }
        }
        return false ;
    }
};