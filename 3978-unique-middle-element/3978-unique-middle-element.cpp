class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size() ;
        
        int mid = n/2, midNum = nums[n/2] ;
        int l = mid - 1, r = mid + 1;

        while(l >= 0 && r < n) {
            if(midNum == nums[l] || midNum == nums[r]) {
                return false ;
            }
            l-- ;
            r++ ;
        }
        return true ;

    }
};