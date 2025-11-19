class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> uset(nums.begin(),nums.end());

        while(uset.find(original) != uset.end()) {
            original *= 2 ;
        }
        return original ;
    }
};