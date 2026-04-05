class Solution {
public:
    bool judgeCircle(string moves) {
        int curr = 0;
        for(int i=0;i<moves.size();i++) {
            if(moves[i] == 'U') {
                curr++ ;
            } else if(moves[i] == 'D') {
                curr-- ;
            } else if(moves[i] == 'L') {
                curr += 5;
            } else {
                curr -= 5 ;
            }
        }
        return curr == 0 ? true : false ;
    }
};