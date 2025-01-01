class Solution {
public:
    int maxScore(string s) {
        int score = 0;

        for(int i=0;i<s.size()-1;++i){
            int left = i, right =left+1;
            int leftscore =0,rightscore =0;

            while(left >=0){
                if(s[left] == '0'){
                    leftscore++ ;
                }
                left--;
            }
            while(right < s.size()){
                if(s[right] == '1'){
                    rightscore++ ;
                }
                right++ ;
            }
            score = max(score,(leftscore+rightscore));
        }
        return score ;
    }
};