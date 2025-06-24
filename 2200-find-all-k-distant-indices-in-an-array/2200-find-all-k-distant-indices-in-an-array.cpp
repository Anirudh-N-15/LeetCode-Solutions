class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans ;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(nums[j] == key && abs(i - j) <= k) {
                    ans.insert(i);
                }
            }
        }
        vector<int> res(ans.begin(),ans.end());
        return res ;
    }
};