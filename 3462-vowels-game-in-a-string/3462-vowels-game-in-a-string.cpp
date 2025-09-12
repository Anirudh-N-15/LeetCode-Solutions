class Solution {
public:
    bool isVowel(char &ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true ;
        }
        return false ;
    }

    bool doesAliceWin(string s) {
        int vowelCount = 0;

        for(char &ch : s) {
            if(isVowel(ch)) {
                vowelCount++ ;
            }
        }
        if(vowelCount == 0) {
            return false ;
        }

        if(vowelCount % 2 != 0) {
            return true ;
        }

        if(vowelCount >= 2) {
            return true ;
        }
        return false ;
    }
};