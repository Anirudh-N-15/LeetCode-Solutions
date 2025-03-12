class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int PosCount = 0, NegCount = 0;

        for(int i=0;i<nums.size();++i){
            if(nums[i] < 0){
                NegCount++ ;
            }
            else if(nums[i] > 0){
                PosCount++ ;
            }
        }
        return max(PosCount, NegCount);
    }
};