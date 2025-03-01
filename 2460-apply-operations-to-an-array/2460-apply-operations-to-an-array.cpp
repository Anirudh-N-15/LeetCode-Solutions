class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n-1;++i){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2 ;
                nums[i+1] = 0 ;
            }
        }

        int j=1,i=0;
        while(i < j && j <n){
            if(nums[i]== 0 && j <n){
                while(nums[j]==0 && j <n-1){
                    j++;
                }
                if(j <n)
                swap(nums[i],nums[j]);
            }
            i++ ;
            j++ ;
        }
        return nums ;
    }
};