class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, prevInc= 0,ans = 0;

        for(int i=1;i<n;i++) {
            if(nums[i] > nums[i-1]) {
                inc++ ;
            } else {
                prevInc = inc ;
                inc = 1;
            }
            ans = max({ans, min(prevInc,inc),inc/2});
        }
        return ans ;
    }
};