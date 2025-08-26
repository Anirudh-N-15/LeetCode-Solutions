//Math based good problem. Just remember that if we place any other number in A[i]
//which is greater than i such that abs(A[i] - i) > 1. Then global maximum exceeds
// the local maximum. And return false.

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(abs(nums[i] - i) > 1) return false ;
        }
        return true ;
    }
};