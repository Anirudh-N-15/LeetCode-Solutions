class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> umap ;
        int count =0;
        for(int i = 0;i < n; ++i) {
            int target = k - nums[i];
            if(umap[target] > 0) {
               count++ ;
               umap[target]-- ;
            } else {
                umap[nums[i]]++ ;
            }
        }
        return count++ ;
    }
};