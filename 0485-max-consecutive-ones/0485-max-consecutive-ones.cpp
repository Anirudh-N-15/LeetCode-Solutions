class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //Prefix Sum based approach
        int n = nums.size();
        for(int i=1;i<n;++i) {
            if(nums[i] == 1 && nums[i-1] >= 1){
                nums[i] += nums[i-1]; 
            }
        }
        return *(max_element(nums.begin(),nums.end()));
    }
};