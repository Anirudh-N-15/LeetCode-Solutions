class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(nums.begin(),nums.end());
        for(const auto &num : nums) {
            ans.push_back(num);
        }
        return ans ;
    }
};