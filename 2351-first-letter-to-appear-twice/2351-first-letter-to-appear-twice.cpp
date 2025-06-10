class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> check;

        for(const char &ch : s) {
            if(check.find(ch) != check.end()) {
                return ch ;
            } else {
                check.insert(ch) ;
            }
        }
        return ' ';
    }
};