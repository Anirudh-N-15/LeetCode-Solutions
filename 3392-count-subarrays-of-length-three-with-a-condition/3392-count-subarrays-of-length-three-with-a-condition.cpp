class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n= nums.size(), count = 0;
        int ptr1 = 0, ptr2 = 2;
        while(ptr2 < n){
            if(nums[ptr1] + nums[ptr2] == nums[(ptr2-1)]/2.0){
                count++ ;
            }
            ptr1++ ;
            ptr2++ ;
        }
        return count ;
    }
};