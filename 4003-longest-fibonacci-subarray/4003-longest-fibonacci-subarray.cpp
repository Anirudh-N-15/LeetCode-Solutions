class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0 ;
        int ans = 2 ;
        for (int right = 2; right < n; right++) {
            while(right < n && nums[right -2] + nums[right -1] == nums[right]) {
                ans = max(ans,right - left + 1);
                right++ ;
            }
            
            left = right - 1 ;
        }
        return ans ;
    }
};