class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double total = INT_MIN;
        double currSum = 0;
        int start = 0;
        int n = nums.size();
        for(int end = 0;end < n;end++) {
            currSum += nums[end] ;

            if(end - start + 1 > k) {
                currSum -= nums[start];
                start++ ;
            }
            
            if(end - start + 1 == k) {
                total = max(total,(currSum)/k);
            }
        }
        return total ;
    }
};