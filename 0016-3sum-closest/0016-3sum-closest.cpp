class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end()) ;
        int ans ;
        cout << ans ;

        for(int i=0;i<n;++i) {
            int j = i + 1, k = n -1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k] ;
                if(abs(target - sum) < abs(target - ans)) {
                    ans = sum ;
                }
                
                if(sum < target) {
                    j++ ;
                }
                else if(sum > target){
                    k-- ;
                } else {
                    return sum ;
                }
            }
        }
        return ans ;
    }
};