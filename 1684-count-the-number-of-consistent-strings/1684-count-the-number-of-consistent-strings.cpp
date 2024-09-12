class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count =0 ;
        unordered_set <char> allowedset(allowed.begin(),allowed.end());

        for(const string &word : words){
           bool isconsistent = true ;

           for(char c : word){
                if(allowedset.find(c)==allowedset.end()){
                    isconsistent = false ;
                    break ;
                }
           }
           if(isconsistent){
            count++ ;
           }
        }
        return count ;
    }
};