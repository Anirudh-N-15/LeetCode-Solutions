class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        vector<int> products;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                products.push_back(nums[i] * nums[j]);
            }
        }
        sort(products.begin(), products.end());

        int count = 1;
        int ans = 0;
        n = products.size();
        for (int i = 1; i < n; i++) {
            if (products[i] == products[i - 1]) {
                count++;
            } else {
                ans += count * (count - 1) * 4;
                count = 1;
            }
        }
        ans += count * (count - 1) * 4;

        return ans;
    }
};