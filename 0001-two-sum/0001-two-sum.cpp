class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;

        for(int i=0;i<nums.size();++i){
            int find = target - nums[i] ;

            if(umap.find(find) != umap.end()){
                return {i,umap[find]};
            } else {
                umap.insert({nums[i],i});
            }
        }
        return {0,0} ;
    }
};