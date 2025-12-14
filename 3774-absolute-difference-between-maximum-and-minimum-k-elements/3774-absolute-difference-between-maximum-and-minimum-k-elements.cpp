class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxSum = 0, minSum = 0;
        int n = nums.size();
        for(int i=0;i<k;i++) {
            minSum += nums[i] ;
        }
        for(int i=n-1;i>=n-k;i--) {
            maxSum += nums[i] ;
        }

        return abs(maxSum - minSum) ;
    }
};