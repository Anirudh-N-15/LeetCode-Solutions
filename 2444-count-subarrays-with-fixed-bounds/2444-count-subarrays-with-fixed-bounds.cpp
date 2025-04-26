class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int l=0,r=0,n = nums.size();
        int max_so_far = INT_MIN, min_so_far = INT_MAX ;
        int minPos = -1, maxPos = -1;

        while(r < n){
            //First find out the min value and max value in the subarray
            max_so_far = max(max_so_far,nums[r]);
            min_so_far = min(min_so_far,nums[r]);

            //If any cond. is violated then skip by doing l = r + 1
            if(max_so_far > maxK || min_so_far < minK){
                l = r + 1;
                min_so_far = INT_MAX, max_so_far = INT_MIN;
            } else {
                if(nums[r] == minK){
                    minPos = r;
                }
                if(nums[r] == maxK){
                    maxPos = r;
                }

                int Posmin = min(minPos,maxPos);
                if(minK == min_so_far && maxK == max_so_far){
                    ans += Posmin - l + 1;
                }
            }
            r++ ;
        }
        return ans ;
    }
};