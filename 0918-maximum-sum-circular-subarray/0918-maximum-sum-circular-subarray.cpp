class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int CurrMax = 0,CurrMin = 0;
        int maxSum = nums[0],minSum = nums[0] ;

        for(int i=0;i<n;++i){
            CurrMax = max(CurrMax+nums[i],nums[i]);
            maxSum = max(maxSum,CurrMax);

            CurrMin = min(CurrMin+nums[i],nums[i]);
            minSum = min(minSum,CurrMin);

            totalSum += nums[i] ;
        }
        int circularSum = totalSum - minSum;

        if(totalSum==minSum){
            return maxSum ;
        }
        return max(maxSum,circularSum);
    }
};