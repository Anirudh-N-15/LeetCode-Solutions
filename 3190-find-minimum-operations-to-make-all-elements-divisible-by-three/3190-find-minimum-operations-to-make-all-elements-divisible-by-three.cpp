class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int mod, sub, ans = 0 ;

        for(int i =0;i < nums.size();++i) {
            mod = nums[i] % 3;
            sub = abs(nums[i] +1) % 3;
            if(sub == 0){
                sub = 1;
            }
            ans += min(mod,sub);
        }
        return ans ;
    }
};