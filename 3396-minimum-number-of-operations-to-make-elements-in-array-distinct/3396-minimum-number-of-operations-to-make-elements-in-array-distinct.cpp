class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        vector<bool> count(101);
        for(int i= nums.size()-1;i>=0;i--){
            if(count[nums[i]]){
                return i/3  + 1 ;
            }
            count[nums[i]] = true ;
        }
        return 0 ;
    }
};