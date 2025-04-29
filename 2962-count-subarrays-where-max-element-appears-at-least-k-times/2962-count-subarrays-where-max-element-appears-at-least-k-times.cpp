class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        vector<int> count;
        int max = *max_element(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=0;i<n;++i){
            if(nums[i] == max){
                count.push_back(i);
            }
            if(count.size() >= k){
                ans += count[count.size() - k] + 1;
            }
        }
        return ans ;
        
    }
};