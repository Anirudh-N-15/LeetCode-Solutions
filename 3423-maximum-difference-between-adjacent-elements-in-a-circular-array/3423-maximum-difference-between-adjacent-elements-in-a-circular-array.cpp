class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int res = abs(nums[0]-nums[1]);

        for(int i=2;i<n;++i){
            res = max(abs(nums[i-1]-nums[i]),res);

            if(i == n-1) {
                res = max(abs(nums[n-1]-nums[0]),res);
            }
        }
        return res ;
    }
};