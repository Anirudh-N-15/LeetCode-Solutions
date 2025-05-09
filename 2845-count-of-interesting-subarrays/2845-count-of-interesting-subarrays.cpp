class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        long long ans = 0;
        int prefix = 0;
        count[0] = 1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i] % modulo == k;
            ans += count[(prefix - k + modulo) % modulo];
            count[prefix % modulo]++;
        }
        return ans;
    }
};