class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size() ;
        for (int i = 0; i < nums.size(); i++)
            nums[i] = abs(nums[i]);

        sort(nums.begin(), nums.end());

        return (long long)(nums[n - 1]) * (nums[n - 2]) * 100000;
    }
};