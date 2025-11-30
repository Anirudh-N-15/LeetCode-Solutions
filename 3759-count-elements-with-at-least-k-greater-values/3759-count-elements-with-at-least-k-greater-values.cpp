class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<n;i++) {
            auto it = upper_bound(nums.begin() + i +1,nums.end(),nums[i]);
            int count = (n - (it - nums.begin()));
            if(count >= k) {
                ans++ ;
            }
        }
        return ans ;
    }
};