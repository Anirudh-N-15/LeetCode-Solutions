class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            bool flag = false  ;
            for (int j = 1; j < nums[i] ; j++) {
                if((j | j + 1) == nums[i]) {
                    ans[i] = j ;
                    flag = true ;
                    break ;
                }
            }
            if(!flag) {
                ans[i] = -1 ;
            }
        }
        return ans ;
    }
};