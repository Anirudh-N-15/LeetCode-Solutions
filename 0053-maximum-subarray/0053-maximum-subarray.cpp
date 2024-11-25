class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0],max_here = nums[0] ;

        for(int i=1;i<nums.size();++i){
            max_here = max(max_here+nums[i],nums[i]);

            result = max(result,max_here);
        }
        return result ;
    }
};