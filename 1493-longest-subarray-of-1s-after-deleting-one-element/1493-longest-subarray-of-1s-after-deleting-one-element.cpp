class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left =0;
        int k = 1,ans = 0;

        for(int right =0; right < n;right++) {
            if(nums[right] == 0) {
                k-- ;
            }
            while(k < 0) {
                if(nums[left] == 0) {
                    k++ ;
                }
                left++ ;
            }
            ans = max(ans,right - left);
        }
        return ans ;
    }
};