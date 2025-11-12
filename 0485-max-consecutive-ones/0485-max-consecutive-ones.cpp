class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 1) return 1;
        int left = 0;
        int n = nums.size();
        int ans = 0;
        for (int right = 1; right < n; right++) {
            while(right < n && nums[right] == 1 ) {
                right++ ;
            }

            if(nums[left] == 1) ans = max(ans,right - left);
            else ans = max(ans,right - left - 1);
            left = right ;
        }
        return ans ;
    }
};