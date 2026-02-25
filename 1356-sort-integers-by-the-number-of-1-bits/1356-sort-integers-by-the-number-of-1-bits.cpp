class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>> mp ;
        for(int i : arr) {
            mp[__builtin_popcount(i)].push_back(i);
        }

        vector<int> ans ;

        for(auto &[k,nums] : mp) {
            sort(nums.begin(),nums.end());

            for(int num : nums) {
                ans.push_back(num);
            }
        }
        return ans ;
    }
};