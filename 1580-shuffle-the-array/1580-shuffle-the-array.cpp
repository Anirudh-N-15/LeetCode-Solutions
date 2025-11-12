class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n) ;
        int i=0;
        for(int j=0;j<n;j++) {
            ans[i] = nums[j] ;
            ans[i+1] = nums[n+j] ;
            i+=2 ;
        }
        return ans ;
    }
};