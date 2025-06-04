class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(accumulate(nums.begin(),nums.end(),0) < target) return 0;

        int left = 0,n = nums.size(), sum = 0;
        int ans = nums.size();

        for(int right = 0;right<n;right++) {
            sum += nums[right];
            while(sum >= target) {
                ans = min(ans,right - left + 1);
                sum -= nums[left];
                left++ ;
            }
        }
        return ans ;
    }
};