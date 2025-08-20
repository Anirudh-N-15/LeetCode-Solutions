class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int startRow = startPos[0], startCol = startPos[1] ;
        int homeRow = homePos[0], homeCol= homePos[1] ;
        int ans = 0;

        if(startRow < homeRow) {
            for(int i=startRow+1;i<=homeRow;i++) {
                ans += rowCosts[i];
            }
        } else {
            for(int i=startRow-1;i>=homeRow;i--) {
                ans += rowCosts[i] ;
            }
        }

        if(startCol < homeCol) {
            for(int i=startCol+1;i<=homeCol;i++) {
                ans += colCosts[i] ;
            }
        } else {
            for(int i=startCol-1;i>=homeCol;i--) {
                ans += colCosts[i] ;
            }
        }
        return ans ;
    }
};