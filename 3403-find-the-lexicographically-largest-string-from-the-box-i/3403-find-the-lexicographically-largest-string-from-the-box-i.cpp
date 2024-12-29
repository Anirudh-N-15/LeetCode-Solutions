class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word ;
        string result = "";
        int length = n - numFriends +1 ;
        for(int i=0;i<n;++i){
            result = max(result,word.substr(i,length));
        }
        return result ;
    }
};