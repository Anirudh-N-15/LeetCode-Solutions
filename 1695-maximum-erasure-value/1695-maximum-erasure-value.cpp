class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> umap;
        int maxVal = 0,currSum = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            umap[nums[r]]++ ;
            currSum += nums[r] ;

            while(umap[nums[r]] > 1) {
                currSum -= nums[l] ;
                umap[nums[l]]-- ;
                l++ ;
            }
            maxVal = max(maxVal,currSum);
        }
        return maxVal ;
    }
};