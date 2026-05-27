class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size() ;
        int count = 0;
        unordered_map<char, int> lower;
        unordered_map<char, int> upper;

        for (int i = 0; i < n; i++) {
            char ch = word[i] ;
            if(islower(word[i])) {
                lower[ch] = i ;
            } else {
                char small = tolower(ch) ;

                if(upper.find(small) == upper.end()) {
                    upper[small] = i ;
                }
            }
        }

        for(auto &[ch,pos] : lower) {
            if(upper.find(ch) != upper.end()) {
                if(pos < upper[ch]) {
                    count++ ;
                }
            }
        }
        return count ;
    }
};