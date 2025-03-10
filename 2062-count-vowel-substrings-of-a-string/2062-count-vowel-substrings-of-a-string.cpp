class Solution {
public:

    int countVowelSubstrings(string word) {
        int count =0;
        int n = word.size();

        for(int i=0;i<n;++i){
            if(!isVowel(word[i])){
                continue;
            }

            unordered_set<char> uset;
            for(int j=i;j<n;++j){
                if(!isVowel(word[j])){
                    break;
                }
                uset.insert(word[j]);

                if(uset.size() == 5){
                    count++ ;
                }
            }   
        }
        return count ;
    }
private:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u'){
            return true;
        } else{
            return false;
        }
    }    
};