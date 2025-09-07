class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(),nums.end());

        if(uset.size() == 1) {
            return 0;
        }
        return 1 ;
    }
};