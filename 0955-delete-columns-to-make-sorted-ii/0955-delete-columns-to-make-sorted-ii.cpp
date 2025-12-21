class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].length() ;
        vector<bool> sorted(n-1,false) ;

        int ans = 0;

        for(int j=0;j<m;j++) {
            bool conflict = false ;

            for(int i=0;i<n-1;i++) {
                if(!sorted[i]) {
                    if(strs[i][j] > strs[i+1][j]) {
                        conflict = true ;
                        break ;
                    }
                }
            }

            if(conflict) {
                ans++ ;
            } else {
                for(int i=0;i<n-1;i++) {
                    if(strs[i][j] < strs[i+1][j]) {
                        sorted[i] = true ;
                    }
                }
            }
        }
        return ans ;
    }
};