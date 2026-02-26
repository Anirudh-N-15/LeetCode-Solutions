class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int num = 0, count = 0;

        for (int i = 0; i < n; i++) {
            num += (s[i] - '0') * pow(2,n-i-1) ;
        }

        while(num > 1) {
            if(num % 2 != 0) {
                num +=1 ;
            } else {
                num /= 2 ;
            }
            count++ ;
        }
        return count ;
    }
};