class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;

        for(int i=0;i<n;i++) {
            totalSum = (totalSum + nums[i]) % p ;
        }
        int target = totalSum % p;
        if(target == 0) return 0;

        unordered_map<int,int> modMap ;
        modMap[0] = -1 ;
        int currSum = 0, minLen = n;

        for(int i=0;i<n;i++) {
            currSum = (currSum + nums[i]) % p ;

            int needed = (currSum - target + p) % p;

            if (modMap.find(needed) != modMap.end()) {
                minLen = min(minLen, i - modMap[needed]);
            }

            modMap[currSum] = i;
        }

        return minLen == n ? -1 : minLen ;

    }
};