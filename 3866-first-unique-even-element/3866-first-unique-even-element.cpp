class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int ans = -1 ;
        unordered_map<int,int> umap ;

        for(const int &num : nums) {
            umap[num]++ ;
        }

        for(int i=0;i<nums.size();i++) {
            if(nums[i] % 2 == 0 && umap[nums[i]] == 1) {
                ans = nums[i] ;
                break ;
            }
        }
        return ans ;
    }
};