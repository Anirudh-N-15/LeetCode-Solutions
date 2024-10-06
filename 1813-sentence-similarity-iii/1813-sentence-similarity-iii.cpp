class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector <string> token1 ;
        vector <string> token2 ;

        stringstream check1(sentence1);
        stringstream check2(sentence2);

        string intermediate1 ;
        string intermediate2 ;

        while(getline(check1,intermediate1,' ')){
            token1.push_back(intermediate1);
        }

        while(getline(check2,intermediate2,' ')){
            token2.push_back(intermediate2);
        }
        
        int fptr1 = 0 ,fptr2 = 0;
        int sptr1 = token1.size()-1,sptr2 = token2.size()-1;

        while (fptr1 <= sptr1 && fptr2 <= sptr2 && token1[fptr1] == token2[fptr2]){
            fptr1++;
            fptr2++;
        }
         
        while (fptr1 <= sptr1 && fptr2 <= sptr2 && token1[sptr1] == token2[sptr2]){
            sptr1--;
            sptr2--;
        } 

         return fptr2 > sptr2 || fptr1 > sptr1;
       
    }
};