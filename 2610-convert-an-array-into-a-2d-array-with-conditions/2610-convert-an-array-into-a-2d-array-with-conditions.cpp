class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> umap ;
        vector<vector<int>> ans ;
        for(const int &num : nums) {
            umap[num]++ ;
        }
        
        while(!umap.empty()) {
            vector<int> res ;
            for(auto it = umap.begin() ; it != umap.end();) {
                res.push_back(it->first);
                it->second-- ;
                if(it->second == 0) {
                   it = umap.erase(it);
                } else {
                    it++ ;
                }
            }
            ans.push_back(res);
        }
        return ans ;
    }
};