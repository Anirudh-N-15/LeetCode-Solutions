class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> currentset ;
        vector <int> temp ;

        backtrack(nums,temp,currentset,0);
        return currentset ;
    }

    void backtrack(vector<int> nums,vector<int> temp ,vector<vector<int>> & currentset,int index){

        currentset.emplace_back(temp);

        if(index == nums.size()){
            return ;
        }

        for(int i=index;i<nums.size();++i){
            temp.emplace_back(nums[i]);
            backtrack(nums,temp,currentset,i+1);
            temp.pop_back() ;
        }
    }
};