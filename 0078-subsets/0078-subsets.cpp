class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp ;
        backtrack(nums,temp,result,0);

        return result ;
    }
private:
    void backtrack(vector<int> nums,vector<int>& temp, vector<vector<int>>& result,int index) {
        result.emplace_back(temp);

        if(index == nums.size()) {
            return;
        }

        for(int i=index;i<nums.size();++i) {
            temp.emplace_back(nums[i]);
            backtrack(nums,temp,result,i+1);
            temp.pop_back();
        }

    }

};