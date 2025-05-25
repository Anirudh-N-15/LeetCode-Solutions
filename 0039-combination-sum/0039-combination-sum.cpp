class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        backTrack(nums,result,temp,target,0);
        return result;
    }
public:
    void backTrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp,
                    int target, int index) {
        if(index == nums.size()) {
            if(target == 0) {
                result.push_back(temp);
            }
            return;
        }

        if(nums[index] <= target) {
            temp.push_back(nums[index]);
            backTrack(nums,result,temp,target - nums[index],index);
            temp.pop_back();
        }

        backTrack(nums,result,temp,target,index+1);
    }
};