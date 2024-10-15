class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size() ;
        long long  count = 0;
        int counter =0 ;

        if(s[n-1]== '0'){
            for(int i=n-1; i>=0; --i){
                if(s[i]=='1'){
                    count += (n-1) - (i + counter) ;
                    counter++ ;
                }
            }
        }

        if(s[n-1]== '1'){
            for(int i=n-1;i>=0;--i){
                if(s[i]=='0'){
                    count += i - counter ;
                    counter++ ;
                }
            }
        }
        return count ;
        
    }
};