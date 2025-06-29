class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = 0;
        int mod = 1e9 + 7;
        vector<int> power(n,1);

        //Precompute powers of 2 since there 2^(right - left) subsequences between
        //left and rigth pointers.
        //We can directly add that to the result.
        for(int i=1;i<n;i++) {
            power[i] = (power[i-1] * 2) % mod ;
        }

        int left = 0, right = n-1;

        while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                count = (count + power[right-left]) % mod ;
                left++ ;
            } else {
                right-- ;
            }
        }
        return count ;
        
    }
};