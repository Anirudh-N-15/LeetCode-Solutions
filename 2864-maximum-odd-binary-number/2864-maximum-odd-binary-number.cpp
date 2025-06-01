class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0;i<n;++i) {
            if(s[i] != '0'){
                count++ ;
            }
        }
        string ans = "";

        for(int i=0;i<count-1;++i) {
            ans += '1' ;
        }
        for(int i=0;i<(n-count);++i) {
            ans += '0' ;
        }
        return ans += '1' ;
    }
};