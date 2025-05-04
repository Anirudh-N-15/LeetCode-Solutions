class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& nums) {
        int ans = 0,n = nums.size();
        for(int i=0;i<n-1; ++i){
            for(int j=i+1;j<n;++j){
                if((nums[i][0] == nums[j][0] && nums[i][1] == nums[j][1]) || (nums[i][1] == nums[j][0] && nums[i][0] == nums[j][1])){
                    ans++ ;
                }
            }
        }
        return ans ;
    }
};