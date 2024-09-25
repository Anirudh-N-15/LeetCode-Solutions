class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false} ;
        bool col[9][9] = {false} ;
        bool box[9][9] = {false} ;

        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j] != '.'){
                    int num = board[i][j]- '0' - 1;
                    int index = (i/3)*3 + j/3 ;

                    if(row[i][num] || col[j][num] || box[index][num]){
                        return false ;
                    }
                    row[i][num] = col[j][num] = box[index][num] = true  ;
                }
            }
        }
        return true ;
    }
};