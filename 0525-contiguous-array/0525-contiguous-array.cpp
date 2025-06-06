class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n= nums.size();
        int zero = 0, one = 0, res = 0;
        unordered_map<int,int> umap; //maps diff(zero ,one) -> index
        for(int i=0;i<n;++i) {
            if(nums[i] == 0) zero++ ;
            else one++ ;

            if(umap.find(one-zero) == umap.end()) {
                umap[one - zero] = i;
            }

            if(zero == one) res = zero + one ;

            else { //It already exits in the hashmap and is the smallest index we have to remove
                int idx = umap[one - zero] ;
                res = max(res,i-idx) ;
            }
        }
        return res ;
    }
};