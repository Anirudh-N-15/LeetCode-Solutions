class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> diff(n+1,0);
        for(int i=0;i<m;++i){
            int l = queries[i][0];
            int r = queries[i][1];
            diff[l] += 1;
            diff[r+1] -= 1;
        }
        for(int i=1;i<n+1;i++) {
            diff[i] = diff[i] + diff[i-1] ;
        }
        
        for(int i=0;i<n;++i) {
            if(diff[i] < nums[i]) {
                return false ;
            }
        }
        return true ;
    }
};