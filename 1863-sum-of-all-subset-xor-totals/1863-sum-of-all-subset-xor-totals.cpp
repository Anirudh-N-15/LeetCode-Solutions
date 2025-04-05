class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans =0 ;
        int n = nums.size();

        for(int &num : nums){
            ans |= num ;
        }

        return ans << (n - 1) ;
    }
};