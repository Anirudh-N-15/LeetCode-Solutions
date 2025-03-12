class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n  = nums.size();
        int posCount = nums.end() - upper_bound(nums.begin(),nums.end(),0);
        int negCount = lower_bound(nums.begin(),nums.end(),0) - nums.begin();

        return max(posCount,negCount);
    }
};