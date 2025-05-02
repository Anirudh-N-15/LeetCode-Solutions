class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0, n = nums.size();

        for(int i=0;i<n;++i){
            if(i > index) return false ;

            index = max(index,nums[i] + i);
        }
        return true ;
    }
};