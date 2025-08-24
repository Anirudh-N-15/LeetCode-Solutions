class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int,int> umap ;
        for(const int &num : nums) {
            umap[num]++ ;
        }

        for(auto &it : umap) {
            int key = it.first, val = it.second ;
            if(val > nums.size()/k){
                return false ;
            }
        }
        return  nums.size() % k == 0;
    }
};