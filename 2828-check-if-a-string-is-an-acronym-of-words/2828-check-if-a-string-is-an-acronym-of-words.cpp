class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
     int  j=0;
     if(words.size()<s.size()){
        return false ;
     }

     for(int i=0;i<words.size();++i ){
        if(words[i][j]==s[i]){
            continue;
        }
        else{
            return false;
        }
     }   
     return true ;
    }
};