class Solution {
public:
    string compressedString(string word) {
        string comp = "" ;
        int i=1,prev ;
        while(i <= word.size()){
            int count = 1 ;
            prev = i -1 ;

            while(word[i-1] == word[i] && count < 9){
                count++ ;
                prev = i-1 ;
                i++ ;
            }
            comp += (to_string(count) + word[prev]) ;

            i++ ;
        }
        return comp ;
    }
};