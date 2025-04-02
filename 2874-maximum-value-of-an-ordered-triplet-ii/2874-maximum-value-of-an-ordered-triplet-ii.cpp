class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxTriplet = 0, maxElement =0, maxDiff = 0;

        for(int &num : nums){
            maxTriplet = max(maxTriplet, maxDiff * num);
            maxDiff = max(maxDiff, maxElement - num);
            maxElement = max(maxElement, (long long)num);
        }
        return maxTriplet ;
    }
};