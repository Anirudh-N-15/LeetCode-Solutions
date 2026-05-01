class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, n = nums.size(), sum = accumulate(nums.begin(),nums.end(),0) ;

        for(int i = 0; i < n; i++) {
            f += i * nums[i] ; 
        }
        int ans = f ;

        for(int i = n -1; i >=0 ; i--) {
            f += sum - n*nums[i] ;
            ans = max(f,ans);
        }
        return ans ;
    }
};