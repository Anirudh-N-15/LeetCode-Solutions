class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0], ans = nums[0];

        for(int i=1;i<nums.size();++i) {
            max_so_far = max(nums[i],max_so_far + nums[i]);
            ans = max(ans,max_so_far);
        }
        return ans ;
    }
};