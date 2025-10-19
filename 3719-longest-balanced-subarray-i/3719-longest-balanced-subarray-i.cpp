class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0;
        for(int i=0;i<n;i++) {
            unordered_set<int> odd,even ;
            int j;
            for(j=i;j<n;j++) {
                if(nums[j] % 2 != 0) {
                    odd.insert(nums[j]);
                } else {
                    even.insert(nums[j]);
                }

                if((int)odd.size() == (int)even.size()) {
                    ans = max(ans, j - i + 1);
                }
            }   
        }
        return ans ;
    }
};