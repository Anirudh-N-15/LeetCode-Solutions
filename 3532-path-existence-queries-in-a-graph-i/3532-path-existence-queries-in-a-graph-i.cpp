class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int size = queries.size() ;
        vector<bool> ans;
        vector<int> cmp(n) ;

        for(int i = 1; i < n; i++) {
            cmp[i] = cmp[i-1] + (nums[i] - nums[i-1] > maxDiff) ;
        }

        for(const auto &query : queries) {
            int u = query[0], v = query[1] ;

            if(cmp[u] == cmp[v]) ans.push_back(true) ;
            else ans.push_back(false) ;
        }
        return ans ;
    }
};