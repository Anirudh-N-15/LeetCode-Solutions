class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2;) {
            vector<int> three;
            int j;
            for (j = i; j < (i + 3); j++) {
                three.push_back(nums[j]);
            }
            ans.push_back(three);
            i = j;
        }

        for(auto it : ans) {
            if(it[2] - it[0] > k) return {} ;
        }

        return ans ;
    }
};