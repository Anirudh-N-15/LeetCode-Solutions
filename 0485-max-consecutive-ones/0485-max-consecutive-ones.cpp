class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //Sliding window based approach
        int n = nums.size();
        int count = 0, ans = 0;
        for(int i=0;i<n;++i) {
            if(nums[i]!=0){
                count++ ;
            } else {
                count = 0;
            }
            ans = max(ans,count);
        }
            return ans ;
    }
};