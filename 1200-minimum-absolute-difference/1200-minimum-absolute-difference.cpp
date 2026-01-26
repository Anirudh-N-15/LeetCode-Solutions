class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> ans ;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX ;
        for(int i=1;i<n;i++) {
            mini = min(nums[i] - nums[i-1], mini) ;
        }

        for(int i=1;i<n;i++) {
            if(nums[i] - nums[i-1] == mini) {
                ans.push_back({nums[i-1],nums[i]});
            }
        }
        return ans ;
    }
};