class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,0);

        int left =0, right = nums.size() -1;

        while(left < right) {
            if(nums[left] + nums[right] == target) {
                res[0] = left+1;
                res[1] = right+1;
                return res ;
            } else if(nums[left] + nums[right] < target) {
                left++ ;
            } else {
                right-- ;
            }
        }
        return res ;
    }
};