class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> count(100);
        int ans = 0;

        for(auto it : dominoes){
            int val = it[0] < it[1] ? 10*it[0] + it[1] : 10*it[1] + it[0] ;
            ans += count[val];
            count[val]++ ;
        }
        return ans ;
    }
};