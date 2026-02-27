class Solution {
public:
    int calc(char ch) {
        if(ch == '0') {
            return 1;
        }
        int num = ch - '0' ;
        int ans = 1 ;
        for (int i = 1; i <= num; i++) {
            ans *= i ;
        }

        return ans ;
    }

    bool isDigitorialPermutation(int n) {
        string s = to_string(n);
        string t = "" ;
        int ans = 0 ;

        for (const char& ch : s) {
            ans += calc(ch) ;
        }
        t = to_string(ans) ; 

        if(is_permutation(s.begin(),s.end(),t.begin())) return true ;

        return false ;
    }
};