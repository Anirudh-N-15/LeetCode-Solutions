class Solution {
public:
    void guardMarked(vector<vector<int>>& isGuarded,int row,int col) {
        int m = isGuarded.size(), n = isGuarded[0].size() ;
        for(int i=row + 1;i<m;i++) {
            if(isGuarded[i][col] == 2 || isGuarded[i][col] == 1) break ;
            isGuarded[i][col] = 5 ;
        }
        for(int i=row -1;i>=0;i--) {
            if(isGuarded[i][col] == 2 || isGuarded[i][col] == 1) break ;
            isGuarded[i][col] = 5 ;
        }
        for(int j=col +1;j<n;j++) {
            if(isGuarded[row][j] == 2 || isGuarded[row][j] == 1) break ;
            isGuarded[row][j] = 5 ;
        }
        for(int j=col-1;j>=0;j--) {
            if(isGuarded[row][j] == 2 || isGuarded[row][j] == 1) break ;
            isGuarded[row][j] = 5 ;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> isGuarded(m,vector<int>(n,false));

        for(const auto &it : guards) {
            int u = it[0] ;
            int v = it[1] ;
            isGuarded[u][v] = 1 ;
        }
        for(const auto &it : walls) {
            int u = it[0] ;
            int v = it[1] ;
            isGuarded[u][v] = 2 ;
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(isGuarded[i][j] == 1) {
                    guardMarked(isGuarded,i,j);
                }
            }
        }
        int count = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(isGuarded[i][j] == 0) {
                    count++ ;
                }
            }
        }
        return count ;
    }
};