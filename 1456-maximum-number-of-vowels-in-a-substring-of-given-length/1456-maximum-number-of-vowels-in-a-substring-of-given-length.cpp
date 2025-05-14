class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0, n = s.size(),count=0;

        for(int i=0;i<k;++i) {
            if(isVowel(s[i])) {
                count++ ;
            }
        }
        res = count ;

        for(int i = k; i < n; i++) {
            if(isVowel(s[i - k])) count-- ;
            if(isVowel(s[i])) count++ ;
            res = max(res,count) ;
        }
        return res ;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ;
    }    
};