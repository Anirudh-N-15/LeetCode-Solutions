class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        int n = s.size();

        for(int i=0;i < n; ++i){
            if(iswalnum(s[i]) == 0){
                continue ;
            } else {
                if(isupper(s[i]) != 0){
                    res += tolower(s[i]);
                }else {
                    res += s[i] ;
                }
            }
        }
        cout << res << " " <<res.size() ;

        int m = res.size() ;
        for(int i=0;i<m/2;i++){
            if(res[i] != res[m-i-1]){
                return false ;
            }
        }
        return true ;
    }
};