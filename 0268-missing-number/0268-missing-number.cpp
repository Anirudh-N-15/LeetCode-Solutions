class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int originalSum = 0,sum = 0;

        for(int i=0;i<n;++i){
            sum += nums[i] ;
        }

        originalSum = (n*(n+1))/2 ;

        return originalSum - sum ;
    }
};