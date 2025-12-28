class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n), suffix(n);
        prefix[0] = nums[0], suffix[n-1] = nums[n-1] ;
        for(int i=1;i<n;i++) {
            prefix[i] = prefix[i-1] + nums[i] ;
        }
        for(int i=n-2;i>=0;i--) {
            int mini = min(suffix[i+1],(long long)nums[i+1]);
            suffix[i] = mini ;
        }
        long long ans = INT_MIN;

        for(int i=0;i<n-1;i++) {
            ans = max(ans,prefix[i] - suffix[i]) ;
        }
        return ans ;
    }
};