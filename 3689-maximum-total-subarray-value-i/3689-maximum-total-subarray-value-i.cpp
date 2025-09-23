class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());

        
        return (long long)(maxi - mini) * (long long)k ;
    }
};