class Solution {
public:
    int m,n;

    bool backtrack(int i, int j, int index, string& word, vector<vector<char>>& board,vector<pair<int,int>> dirs){
        if(board[i][j] != word[index]) {
            return false ;
        }
        if(index == word.size() - 1) return true ;

        char original = board[i][j] ;
        board[i][j] = '#' ;

        bool ans = false ;
        for(auto dir : dirs) {
            int nrow = i + dir.first ;
            int ncol = j + dir.second ;

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] != '#') {
                if(backtrack(nrow,ncol,index +1,word,board,dirs)) {
                    ans = true ;
                    break;
                }
            }
        }

        board[i][j] = original ;
        return ans ;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0] && backtrack(i,j,0,word,board,dirs)) {
                    return true ;
                }
            }
        }
        return false ;
    }
};