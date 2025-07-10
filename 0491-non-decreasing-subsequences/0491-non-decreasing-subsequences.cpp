class Solution {
public:
    void solve(int index, set<vector<int>>& ans, vector<int>& res, vector<int>& nums) {
        if(res.size() > 1){
            ans.insert(res);
        }
        if(index == nums.size()){
            return ;
        }
        if(res.size() == 0 || res.back() <= nums[index]){
            res.push_back(nums[index]);
            solve(index+1,ans,res,nums);
            res.pop_back();
        }
        solve(index +1,ans,res,nums);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> res ;
        set<vector<int>> ans;
        solve(0,ans,res,nums);

        return vector(ans.begin(),ans.end());
    }
};