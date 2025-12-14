class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ;
    }

    int countVowel(string str) {
        int count = 0;
        for(const char &ch : str) {
            if(isVowel(ch)) {
                count++ ;
            }
        }
        return count ;
    }

    string reverseWords(string s) {
        string ans = "" ;
        stringstream ss(s) ;
        string word ;
        ss >> word ;
        int count = countVowel(word) ;

        ans += word + " " ;

        while(ss >> word) {
            int currCount = countVowel(word);

            if(currCount == count) {
                reverse(word.begin(),word.end());
            }
            ans += word + " " ;
        }
        ans.pop_back() ;
        return ans;
    }
};