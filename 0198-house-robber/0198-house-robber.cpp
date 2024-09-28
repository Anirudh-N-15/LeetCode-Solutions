class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0] ;

        int prev1 =0 ;
        int prev2 =0 ;

        for(int i=0;i<nums.size();++i){
            int current = max(prev1,nums[i]+prev2);

            prev2 = prev1 ;
            prev1 = current;
        }
        return prev1 ;
    }
};