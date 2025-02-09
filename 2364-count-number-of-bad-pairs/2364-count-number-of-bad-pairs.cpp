class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long> umap ;
        long long  n = nums.size();
        long long totalPairs = (n * (n-1))/2 ;
        long long goodPairs = 0;

        for(int i=0;i<n;++i){
            int key = nums[i] - i ;
            if(umap.count(key)){
                goodPairs += umap[key];
            }
            umap[key]++ ; 
        }

        return totalPairs - goodPairs ;
    }
};