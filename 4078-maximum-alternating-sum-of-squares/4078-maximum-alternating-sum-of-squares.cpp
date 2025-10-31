class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end(), greater<int>());
        bool flag = false;
        if (n % 2 == 0) {
            flag = true;
        }

        long long ans = 0;

        if (flag) {
            for (int i = 0; i < n ; i++) {
                if (i >= n / 2) {
                    ans -= (nums[i] * nums[i]);
                } else {
                    ans += (nums[i] * nums[i]);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (i > n / 2) {
                    ans -= (nums[i] * nums[i]);
                } else {
                    ans += (nums[i] * nums[i]);
                }
            }
            
        }

        return ans;
    }
};