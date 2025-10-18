class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0, prev = INT_MIN;

        for (const int& num : nums) {
            int curr = min(max(prev + 1, num - k), num + k);
            if (curr > prev) {
                prev = curr;
                ans++;
            }
        }
        return ans;
    }
};