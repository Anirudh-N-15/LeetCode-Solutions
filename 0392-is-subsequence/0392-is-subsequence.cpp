class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int count = 0;
        for(int i=0;i<n;++i){
            if(s[count] == t[i]){
                count++ ;
            } 
        }
        return count == s.size() ? true : false ;
    }
};