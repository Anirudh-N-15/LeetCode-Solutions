class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int i=0;i<n;i++) {
            int count = 0;
            if(nums[i] == 0) {
                while(i < n && nums[i] == 0) {
                    count++ ;
                    i++ ;
                    ans += count ;
                }
            }
        }
        return ans ;
    }
};