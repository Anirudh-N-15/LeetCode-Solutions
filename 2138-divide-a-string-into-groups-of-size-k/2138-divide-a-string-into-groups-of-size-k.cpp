class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;

        for(int i=0;i<n;) {
            string res = "" ;
            while(i < n &&res.size() < k) {
                res += s[i] ;
                i++ ;
            }
            ans.push_back(res);
        }
        int m = ans.size();
        while(ans[m-1].size() < k) {
            ans[m-1] += fill ;
        }
        return ans ;
    }
};