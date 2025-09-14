class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;
        for(const auto &it : tasks) {
            int curr = 0;
            curr = it[0] + it[1] ;
            ans = min(curr,ans);
        }
        return ans ;
    }
};