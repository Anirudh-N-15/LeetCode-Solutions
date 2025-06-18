class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int count = 0,j=0;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;) {
            while(j < n && nums[j] - nums[i] <= k) {
                j++ ;
            }
            count++ ;
            i = j;
        }
        return count ;
    }
};