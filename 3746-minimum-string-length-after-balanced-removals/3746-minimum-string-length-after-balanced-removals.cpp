class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int count_a = 0, count_b = 0;

        for(const char &ch : s) {
            if(ch == 'a') count_a++ ;
            else count_b++ ;
        }
        return abs(count_a - count_b) ;
    }
};