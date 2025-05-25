class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> temp;
        backtrack(nums,temp,result,0);

        vector<vector<int>> res(result.begin(),result.end());
        return res;
    }
private:
    void backtrack(vector<int> nums,vector<int>& temp,set<vector<int>>& result,int index) {
        result.insert({temp});

        if(index == nums.size()) return ;

        for(int i=index;i<nums.size();++i) {
            temp.emplace_back(nums[i]);
            backtrack(nums,temp,result,i+1);
            temp.pop_back();
        }
    }
};