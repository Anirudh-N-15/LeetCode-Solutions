class Solution {
public:
    string reversed(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    string invert(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
        return s ;
    }

    char findKthBit(int n, int k) {
        string ans = "0";

        for (int i = 1; i <= n; i++) {
            string s = invert(ans);
            
            ans = ans + "1" + reversed(s) ;
        }

        return ans[k-1] ;
    }
};