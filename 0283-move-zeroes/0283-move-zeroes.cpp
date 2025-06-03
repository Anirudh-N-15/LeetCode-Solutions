class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=1;

        while(j<nums.size()){
            if(nums[i] == 0 && nums[j]!=0){
                swap(nums[i],nums[j]);
            }
            while(i < n && nums[i]!= 0){
                i++ ;
                j = i+1;
            }
            while(j<n && nums[j] == 0){
                j++ ;
            }
        }
    }
};