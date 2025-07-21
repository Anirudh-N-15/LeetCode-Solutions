class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0) return nums[0];

        if(k%2 != 0 && n == 1) return -1 ;

        int ans1 = 0;
        for(int i=0;i< min(n,k-1);i++) {
            ans1 = max(ans1,nums[i]);
        }

        int ans2 =0;
        if(k < n) ans2 = nums[k];

        return max(ans1,ans2);        
    }
};