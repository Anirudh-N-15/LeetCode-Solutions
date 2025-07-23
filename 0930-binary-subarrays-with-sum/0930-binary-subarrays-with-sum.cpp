class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int start = 0, total = 0, prefix0 = 0, currSum = 0;

        for(int end = 0; end < n;end++) {
            currSum += nums[end] ;

            while(start < end && (nums[start] == 0 || currSum > goal)) {
                if(nums[start] == 0) {
                    prefix0++ ;
                } else {
                    prefix0 = 0;
                }

                currSum -= nums[start];
                start++ ;
            }

            if(goal == currSum) {
                total += 1 + prefix0 ;
            }
        }
        return total ;
    }
};