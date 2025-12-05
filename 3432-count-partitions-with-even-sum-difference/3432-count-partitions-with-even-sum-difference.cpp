class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int curr = 0;
        for(int i=0;i<n-1;i++) {
            
            if((nums[i] - (sum - (curr + nums[i])))% 2 == 0) {
                count++ ;
            }
            curr += nums[i] ;
            sum -= nums[i] ;
        }
        return count ;
    }
};