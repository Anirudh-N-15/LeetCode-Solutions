class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int,vector<int>> groupFreq ;
        vector<vector<int>> ans ;

        for(int i=0;i<n;++i) {
            groupFreq[groupSizes[i]].push_back(i);

            if(groupFreq[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(groupFreq[groupSizes[i]]);
                groupFreq[groupSizes[i]].clear();
            }
        }
        return ans ;
    }
};