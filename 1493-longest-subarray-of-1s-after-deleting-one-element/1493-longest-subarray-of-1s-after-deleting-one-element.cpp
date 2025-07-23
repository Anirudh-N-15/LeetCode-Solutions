class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, k = 1;
        int n = nums.size();
        for (int end = 0; end < n; end++) {
            if(nums[end] == 0) {
                k-- ;
            }
            if(k < 0) {
                if(nums[start] == 0) {
                    k++ ;
                }
                start++ ;
            }
        }
        return n - start -1 ;
    }
};