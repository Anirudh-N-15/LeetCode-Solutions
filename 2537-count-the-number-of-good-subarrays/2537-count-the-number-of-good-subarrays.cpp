class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int equal = 0, r = -1;
        unordered_map<int, int> count;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            while (equal < k && r + 1 < n) {
                ++r;
                equal += count[nums[r]];
                ++count[nums[r]];
            }
            if (equal >= k) {
                ans += n - r;
            }
            --count[nums[i]];
            equal -= count[nums[i]];
        }
        return ans;
    }
};