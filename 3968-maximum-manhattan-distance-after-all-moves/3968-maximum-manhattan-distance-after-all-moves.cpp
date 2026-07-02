class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.size() ;
        int count  = 0;

        pair<int,int> ans = {0,0} ;

        for(int i = 0; i < n; i++) {
            if(moves[i] == 'L') {
                ans.first += -1 ;
            } else if(moves[i] == 'D') {
                ans.second += -1 ;
            } else if(moves[i] == 'U') {
                ans.second += 1 ; 
            } else if(moves[i] == 'R') {
                ans.first += 1 ;
            } else {
                count++ ;
            }
        }


        return abs(ans.first) + abs(ans.second) + count  ;
    }
};