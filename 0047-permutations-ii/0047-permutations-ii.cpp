class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> uset ;
        permutations(uset,nums,0);
        vector<vector<int>> result(uset.begin(),uset.end()) ;

        return result;
    }
    void permutations(set<vector<int>>& uset,vector<int>& nums,int index){

        if(index == nums.size()){
            uset.insert({nums});
            return ;
        }

        for(int i =index;i< nums.size();++i){
            swap(nums[index],nums[i]);
            permutations(uset,nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
};