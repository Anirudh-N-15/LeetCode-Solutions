class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count =0, words = 0 ;
        unordered_set<char> uset ;
        stringstream ss(text);

        for(const char &ch : brokenLetters) {
            uset.insert(ch) ;
        }

        string s = "";

        while(ss >> s) {
            words++ ;
            for(const char &ch :s) {
                if(uset.find(ch) != uset.end()) {
                    count++ ;
                    break ;
                }
            }
        }
        return words - count ;
    }
};