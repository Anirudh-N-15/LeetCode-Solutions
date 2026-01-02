class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int,int> umap ;
        for(const auto &num : nums) {
            umap[num]++ ;
        }
        int ans = 0;
        for(const auto &it : umap) {
            if(it.second == n) {
                ans = it.first ;
                break ;
            }
        }
        return ans ;
    }
};