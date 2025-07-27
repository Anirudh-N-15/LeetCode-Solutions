class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<int> arr;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                arr.push_back(nums[i]);
            }
        }
        if (arr.size() > 0) {
            if (arr.back() != nums[n - 1]) {
                arr.push_back(nums[n - 1]);
            }
        }

        n = arr.size();
        if (n == 1 || n == 0)
            return 0;

        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                count++;
            } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                count++;
            }
        }
        return count;
    }
};