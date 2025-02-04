class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int max_so_far = nums[0], curr_max = nums[0];

        for(int i=0;i<n-1;++i){
            if(nums[i+1] > nums[i]) {
                max_so_far += nums[i+1];
                curr_max = max(max_so_far, curr_max);
            }
            else {
                max_so_far = nums[i+1];
            }
        }
        return curr_max ;
    }
};