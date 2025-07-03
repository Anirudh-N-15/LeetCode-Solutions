class Solution {
public:
    char kthCharacter(int k) {
        string word = "a" ;
        while(word.size() < k) {
            string append = "" ;
            for(const char &ch : word) {
                append += (ch  + 1) ;
            }
            word += append ;
        }
        return word[k -1] ;
    }
};