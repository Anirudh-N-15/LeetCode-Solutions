class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int count = 0, positiveMin = INT_MAX, negativeMin = INT_MIN;
            
        for (int nodeValue : nums) {
            int operatedNodeValue = nodeValue ^ k;
            sum += nodeValue;
            int netChange = operatedNodeValue - nodeValue;
            
            if (netChange > 0) {
                positiveMin = min(positiveMin, netChange);
                sum += netChange;
                count++;
            } else {
                negativeMin = max(negativeMin, netChange);
            }
        }
        
        // If the number of positive netChange values is even return the sum.
        if (count % 2 == 0) {
            return sum;
        }
        
        // Otherwise return the maximum of both discussed cases.
        return max(sum - positiveMin, sum + negativeMin);
    }
};