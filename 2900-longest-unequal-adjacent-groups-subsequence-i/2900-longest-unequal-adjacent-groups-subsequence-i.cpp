class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<string> res ;
        int grp = groups[0] ;

        for(int i = 0; i < n; i++) {
            if(grp == groups[i]) {
                res.push_back(words[i]);
                grp = !(grp) ;
            }
        }
        return res ;
    }
};