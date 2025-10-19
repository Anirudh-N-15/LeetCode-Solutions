class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vis(101,0);
        for(int i=0;i<n;i++) {
            vis[nums[i]] = 1;
        }   
        int maxIndex = 0;

        for(int i=1;i<=100;i++) {
            if(i % k == 0) {
                if(vis[i] == 0) {
                    return i ;
                } else {
                    maxIndex = max(maxIndex,i);
                }
            }
        }
        return maxIndex + k ;
    }
};