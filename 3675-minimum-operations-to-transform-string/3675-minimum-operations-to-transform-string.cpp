class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool flag = false ;

        for(const char &ch : s) {
            if(ch != 'a') flag = true ;
        }
        if(!flag) return 0 ;

        char minChar = 'z' ;
        int currDiff = 10;

        for(const char &ch : s) {
            if(ch != 'a' && ch - minChar < currDiff) {
                minChar = ch;
                currDiff = ch - minChar ;
            }
        }
        cout << minChar ;

        return ('z' - minChar + 1) ;

    }
};