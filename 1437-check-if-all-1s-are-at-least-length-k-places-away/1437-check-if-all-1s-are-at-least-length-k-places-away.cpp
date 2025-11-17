class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prevIndex= -1; 
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 1) {
                if(prevIndex == -1) {
                    prevIndex = i;
                    continue ;
                }
                if(i - prevIndex-1 < k) {
                    return false ;
                } 
                prevIndex = i;
            }
        }
        return true ;
    }
};