class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        int lastChainElem = INT_MIN;

        for(const auto &pair : pairs) {
            if(lastChainElem < pair[0]) {
                lastChainElem = pair[1] ;
                ans++ ;
            }
        }
        return ans ;
    }
};