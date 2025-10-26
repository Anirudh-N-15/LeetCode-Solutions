class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n) ;
        string buf = "" ;
        long long ans = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] - '0' == 0) {
                continue ;
            } else {
                buf += s[i] ;
            }
        }
        ans = stoll(buf) ;
        return ans ;
    }
};