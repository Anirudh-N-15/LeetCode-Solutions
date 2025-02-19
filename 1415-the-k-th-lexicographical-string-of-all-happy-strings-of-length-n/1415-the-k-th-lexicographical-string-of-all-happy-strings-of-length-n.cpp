class Solution {
public:
    string getHappyString(int n, int k) {
        int totalPerm = 3 * (1 << (n-1)) ;
        if(k > totalPerm) return "" ;

        int i=1, left = k;
        char lastChar = '#' ;
        string result = "";

        while(i <= n && left > 0) {
            int currPerm = 1 << (n-i) ;

            for(char c = 'a' ; c<= 'c' ; c++) {
                if(c == lastChar) {
                    continue ;
                }

                if(left > currPerm) {
                    left -= currPerm ;
                }
                else {
                    result += c;
                    lastChar = c ;
                    i++ ;
                    break;
                }
            }
        }
        return result ;
    }
};