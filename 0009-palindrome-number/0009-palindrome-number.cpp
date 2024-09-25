class Solution {
public:
    bool isPalindrome(int x) {
        string number = to_string(x);

        int i = number.length() -1 ;
        int j =0 ;

        while(j<i){
            if(number[i]!=number[j]){
                return false ;
            }
            i-- ;
            j++ ;
        }
        return true ;
    }
};