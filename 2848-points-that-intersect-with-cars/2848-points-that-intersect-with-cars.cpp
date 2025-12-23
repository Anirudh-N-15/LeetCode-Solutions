class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size() ;
        vector<int> diff(102,0);

        for(const auto &num : nums) {
            int start = num[0], end = num[1] ;
            diff[start]++ ;
            diff[end+1]-- ;
        }

        int ans = 0;   
        for(int i=1;i<101;i++) {
            diff[i] += diff[i-1] ;
            if(diff[i] > 0) {
                ans++ ;
            }
        }
        return ans ;
        
    }
};