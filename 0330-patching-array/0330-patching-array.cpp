class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0, i=0;
        long long sum = 1;

        while(sum <= n) {
            if(i < nums.size() && sum >= nums[i]) {
                sum += nums[i];
                i++ ;
            } else {
                sum += sum ;
                count++ ;
            }
        }
        return count ;
    }
};