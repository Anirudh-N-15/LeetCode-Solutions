class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> uset(nums.begin(),nums.end());
        vector<int> ans ;
        auto it = uset.rbegin();
        while(it != uset.rend() && k--) {
            ans.push_back(*it);
            it++ ;
        }
        return ans ;
    }
};