class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int less = 0, great = n - 1; 
        vector<int> ans(n);

        for(int i = 0, j = n - 1; i < n, j >= 0; i++,j--) {
            if(nums[i] < pivot) {
                ans[less] = nums[i] ;
                less++ ;
            }
            if(nums[j] > pivot) {
                ans[great] = nums[j] ;
                great-- ;
            }
        }
        while(less <= great) {
            ans[less] = pivot;
            less++ ;
        }
        return ans ;
    }
};