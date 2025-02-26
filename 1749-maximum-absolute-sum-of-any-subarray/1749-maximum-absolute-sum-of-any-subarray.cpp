class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> inverted;

        for(int el : nums){
            inverted.push_back(-el);
        }

        return max(maxSubarray(nums),maxSubarray(inverted));
    }
private:
    int maxSubarray(vector<int> nums){
        int currSum = 0, maxSum = 0;

        for(int i : nums){
            currSum = max(0, currSum +i);
            maxSum = max(currSum,maxSum);
        }
        return maxSum ;
    }

};