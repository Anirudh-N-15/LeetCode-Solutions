class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size() ;
        long long ans = 0;
        sort(nums.begin(),nums.end());

        for(int i = n -1; i >= 0, k > 0; i--, k--) {
            if(mul >= 1) {
                ans += (long long)nums[i] * (long long)mul ;
                mul-- ;
            } else {
                ans += nums[i] ;
            }
        }
        return ans ;
    }
};