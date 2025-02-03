class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ptr1 = 0, ptr2 = 0;
        int inc = 0, dec = 0;

        for(int i=0;i<n-1;++i) {
            if(nums[i+1] > nums[i]) {
                ptr2 += 1 ;
            }
            else {
                ptr1 = i+1 ;
                ptr2 = ptr1 ;
            }
            inc = max(ptr2 - ptr1, inc);
        }
        ptr1 = 0,ptr2 =0;

        for(int i=0;i<n-1;++i) {
            if(nums[i+1] < nums[i]) {
                ptr2 += 1 ;
            }
            else {
                ptr1 = i+1;
                ptr2 = ptr1 ;
            }
            dec = max(ptr2 - ptr1, dec);
        }

        return max(inc,dec) +1;
    }
};