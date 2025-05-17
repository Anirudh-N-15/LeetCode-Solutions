class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), dup = k;
        int left = 0, right = 0;
        int length = 0, ans = 0;

        while(right < n) {
            if(nums[right] == 1) {
                length++ ;
                right++ ;
            } else if(nums[right] == 0 && dup > 0) {
                length++ ;
                right++ ;
                dup-- ;
            } else {
                int i = left;
                while(nums[i] != 0 && i < n)
                    i++ ;
                left = i + 1;
                length = right - left ;
                dup++ ;
            }
            ans = max(length,ans) ;
        }
        return ans ;
    }
};