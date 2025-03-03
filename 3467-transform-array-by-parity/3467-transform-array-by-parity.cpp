class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int countOdd = 0,countEven = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]&1){
                countOdd++;
            }
            else{
                countEven++;
            }
        }
        vector<int> ans(nums.size(),1);
        for(int i=0;i<countEven;++i){
            ans[i] =0 ;
        }
        return ans ;
    }
};