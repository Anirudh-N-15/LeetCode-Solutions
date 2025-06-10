class Solution {
public:
    int maxDifference(string s) {
        vector<int> count(26);
        int oddmax =0, evenmin = s.size();

        for(const char &c : s){
            count[c - 'a']++ ;
        }

        for(int i=0;i<26;++i) {
            if(count[i]%2 !=0){
                oddmax = max(oddmax,count[i]);
            } 
            if(count[i] % 2 == 0 && count[i] >0){
                evenmin = min(evenmin,count[i]);
            }
        }

        return oddmax - evenmin ;
    }
};