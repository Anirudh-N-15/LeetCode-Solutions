class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        int ans = -1;

        for (int num : nums) {
            int digit_sum = digitsum(num);
            auto& p = mp[digit_sum];

            if (num > p.first) {
                p.second = p.first;
                p.first = num;
            }

            else if (num > p.second) {
                p.second = num;
            }

            if (mp[digit_sum].second > 0) {
                ans = max(ans, p.first + p.second);
            }
        }

        return ans;
    }

private:
    int digitsum(int num) {
        int digit = 0;

        while (num > 0) {
            digit += (num % 10);
            num = num / 10;
        }

        return digit;
    }
};