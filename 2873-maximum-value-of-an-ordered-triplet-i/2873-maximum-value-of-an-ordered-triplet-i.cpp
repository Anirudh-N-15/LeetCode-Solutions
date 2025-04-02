class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxTriplet = 0, maxElem = 0, maxDiff = 0;

        for(int & num : nums){
            maxTriplet = max(maxTriplet,maxDiff * num);
            maxDiff = max(maxDiff, maxElem - num);
            maxElem = max(maxElem, (long long )num);
        }
        return maxTriplet ;
    }
};