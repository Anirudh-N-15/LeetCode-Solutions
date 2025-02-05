class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), m= s2.size();
        if(n != m) return false ;
        int count = 0;

        vector<int> check(26,0);

        for(int i=0;i<n;++i) {
            check[s1[i]-'a']++;
            check[s2[i]-'a']--;

            if(s1[i] != s2[i]) {
                count++ ;
            }
            if(count > 2){
                return false ;
            }
        }

        for(int i=0;i<26;++i){
            if(check[i]!=0){
                return false ;
            }
        }
        return true ;
    }
};