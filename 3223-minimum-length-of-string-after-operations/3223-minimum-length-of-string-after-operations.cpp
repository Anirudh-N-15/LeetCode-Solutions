class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> count(26,0);

        for(int i=0;i<n;++i) {
            count[s[i]-'a']++ ;
        }

        for(int i=0;i<26;++i) {
            if(count[i] >= 3) {
                if(count[i] %2 !=0){
                    count[i] = 1 ;
                }
                else{
                    count[i] =2 ;
                }
            }
        }
        
        return accumulate(count.begin(),count.end(),0);
    }
};