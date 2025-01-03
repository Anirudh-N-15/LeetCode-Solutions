class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long > prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        prefix[n - 1] = prefix[n - 2] + nums[n - 1];

        int count = 0;

        for (int i = 0; i < n - 1; ++i) {
            if(prefix[i] >= prefix[n-1] - prefix[i]){
                count++ ;
            }
        }
        return count;
    }
};