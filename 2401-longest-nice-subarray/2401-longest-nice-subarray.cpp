class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0, ans = 0, usedBits = 0;

        for(int i=0;i<n;++i){
            while((usedBits & nums[i]) != 0){
                usedBits ^= nums[start];
                start++ ;
            }

            usedBits |= nums[i];

            ans = max(ans, i - start + 1);
        }
        return ans ;
    }
};