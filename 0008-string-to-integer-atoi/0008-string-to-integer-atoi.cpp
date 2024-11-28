class Solution {
public:
    int myAtoi(string s) {
        int res =0,sign =1 ,index = 0 ;

        while(s[index]== ' '){
            index++ ;
        }

        if(s[index]=='-' || s[index]=='+'){
            if(s[index++]== '-'){
                sign = -1 ;
            }
        }

        while( s[index] >= '0' && s[index] <= '9'){
            if(res > INT_MAX/10 || (res == INT_MAX/10 && s[index] - '0' > 7)){
                return sign == 1 ? INT_MAX : INT_MIN ;
            }

            res = res*10 + (s[index++]-'0');
        }
        return res*sign  ;
    }
};