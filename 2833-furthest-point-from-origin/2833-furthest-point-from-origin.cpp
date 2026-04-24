class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0,countR = 0,count = 0, ans = 0;
        for(const char &ch : moves) {
            if(ch == 'L') {
                countL++ ;
            } else if(ch == 'R'){
                countR++ ;
            } else {
                count++ ;
            }
        }

        if(countL - countR == 0) {
            ans = count ;
        }
        if(countL - countR > 0) {
            ans = count + (countL - countR) ;
        }
        if(countR - countL > 0) {
            ans = count + countR - countL ;
        }
        return ans ;
    }
};