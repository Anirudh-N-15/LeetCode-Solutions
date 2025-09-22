class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> umap ;
        int total = 0, maxi = 0;
        for(int num : nums) {
            umap[num]++ ;
            int freq = umap[num] ;
            if(freq > maxi) {
                maxi = freq ;
                total = freq ;
            } else if(freq == maxi) {
                total += freq ;
            }
        }
        return total ;
    }
};