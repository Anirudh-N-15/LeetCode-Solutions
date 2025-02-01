class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int leftsum = 0, rightsum = accumulate(nums.begin(),nums.end(),0);
        int count = 0;
        for(int i=0;i<nums.size()-1;++i) {
            leftsum += nums[i];
            rightsum -= nums[i];
            if(abs(leftsum - rightsum)%2 ==0) count++ ;
        }
        return count ;
    }
};