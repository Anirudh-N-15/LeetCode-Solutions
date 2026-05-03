class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = goal.size() ;
        if(goal.size() != s.size()) return false ;
        s += s ;

        for(int i=0;i<2*n;i++) {
            string sub = s.substr(i,n);
            if(sub == goal) {
                return true ;
            }
        }
        return false ;
    }
};