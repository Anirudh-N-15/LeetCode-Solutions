class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> netChange(n);
        long long nodeSum = 0;

        for(int i=0;i<n;i++) {
            netChange[i] = (nums[i] ^ k) - nums[i] ;
            nodeSum += nums[i] ;
        }
        sort(netChange.begin(),netChange.end(),greater<int>());

        for(int i=1;i<n;i+=2) {
            if(netChange[i-1] + netChange[i] >= 0) {
                nodeSum += netChange[i-1] + netChange[i] ;
            }
        }
        return nodeSum; 

    }
};