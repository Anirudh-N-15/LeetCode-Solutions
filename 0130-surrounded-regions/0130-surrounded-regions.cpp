class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& marked,int row,int col) {
        int m = board.size(), n = board[0].size();
        marked[row][col] = 1;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        for(auto it : dir) {
            int nrow = row + it.first ;
            int ncol = col + it.second ;
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                if(board[nrow][ncol] == 'O' && !marked[nrow][ncol]) {
                    dfs(board,marked,nrow,ncol);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> marked(m,vector<bool>(n,0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    if(board[i][j] == 'O') {
                        dfs(board,marked,i,j);
                    }
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!marked[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X' ;
                }
            }
        }

    }
};