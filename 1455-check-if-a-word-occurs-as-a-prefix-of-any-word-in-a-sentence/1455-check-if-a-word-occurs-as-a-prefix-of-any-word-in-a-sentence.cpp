class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
       int n = sentence.size() ;
       int m = searchWord.size() ;
       int wordIndex =1 ;
       int charIndex = 0 ;

       while(charIndex < n){
        if(sentence[charIndex] != ' '){
            int i = 0 ,start = charIndex ;
            while(charIndex < n && sentence[charIndex]!= ' ' && i<m){
                if (sentence[charIndex] != searchWord[i]) break;
                charIndex++;
                i++;
            }

            if(i==m) return wordIndex ;

            while(charIndex < n && sentence[charIndex]!= ' ') charIndex++ ;
        }
        charIndex++ ;
        wordIndex++ ;
       } 
       return -1 ;
    }
};