class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefix(n,0);
        unordered_map<int,int> freq;

        prefix[0] = nums[0];
        for(int i=1;i<n;++i) {
            prefix[i] = nums[i] + prefix[i-1];
        }

        for(int j=0;j<n;++j) {
            if(prefix[j] == k) count++ ;
            int val = prefix[j] - k;
            if(freq.find(val) != freq.end()){
                count += freq[val] ;
            }
            
            freq[prefix[j]]++ ;
        }
        return count ;
    }
};