class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int i=0,n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        while(i<n){
            int j=i;
            while(j<n && nums[i]==nums[j]) j++;

            // convert to current number in nums 
            // hence we convert every number to the current number so we take previous nums[i]-k to next nums[i]+k elements in range
            int lb=lower_bound(nums.begin(),nums.end(),nums[i]-k)-nums.begin();
            int ub=upper_bound(nums.begin(),nums.end(),nums[i]+k)-nums.begin();
            ans=max(ans,j-i+min(ub-lb-(j-i),numOperations));

            // convert to number not present in nums
            // hence we have to apply operations in every number in nums in range of elements present in range of 2*k
            int ind=upper_bound(nums.begin(),nums.end(),((long long)nums[i]+2*(long long)k))-nums.begin();
            ans=max(ans,min(ind-i,numOperations));
            
            i=j;
        }
        return ans;
    }
};