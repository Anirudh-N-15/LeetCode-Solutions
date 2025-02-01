class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n-1;++i) {
            long long firstsum = 0, lastsum=0;
            for(int j=0;j<=i;++j){
                firstsum += nums[j];
            }
            for(int k=i+1;k<n;++k){
                lastsum += nums[k];
            }
            if(abs(lastsum - firstsum) %2 ==0){
                ans++ ;
            }
        }
        return ans ;
    }
};