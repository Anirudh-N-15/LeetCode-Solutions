class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0,neg=0;

        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                count++ ;
            }
            else if(s[i]==')'){
                count-- ;
            }

            if(count < 0){
                neg++ ;
                count=0;
            }
        }
        return abs(count + neg);
    }
};