class Solution {
public:
    bool isSafe(vector<vector<string>>& result,vector<string>& board,int row,int col,int n) {
        for(int i=0;i<n;++i) {
            if(board[row][i] == 'Q') {
                return false ;
            }
        }
        for(int i=0;i<n;++i) {
            if(board[i][col] == 'Q') {
                return false ;
            }
        }
        for(int i=row,j=col;i>=0 && j>= 0;--i,--j) {
            if(board[i][j] == 'Q') {
                return false ;
            }
        }
        for(int i=row,j=col;i>=0 && j>= 0;--i,++j) {
            if(board[i][j] == 'Q') {
                return false ;
            }
        }
        return true ;
    }

    void nQueens(vector<vector<string>>& result,vector<string>& board,int n,int row) {
        if(row == n) {
            result.push_back(board);
            return;
        }

        for(int j=0;j<n;++j) {
            if(isSafe(result,board,row,j,n)) {
                board[row][j] = 'Q' ;
                nQueens(result,board,n,row+1);
                board[row][j] = '.' ;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.')) ;
        vector<vector<string>> result;
        nQueens(result,board,n,0);
        return result;
    }
};