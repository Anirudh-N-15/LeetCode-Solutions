class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set <string> bannedset (bannedWords.begin(),bannedWords.end());
        int count =0 ;
        for(auto const &word : message){
            if(bannedset.find(word)!=bannedset.end()){
                count++ ;
            }
            if(count >=2)
            return true ;
        }
        return false ;
    }
};