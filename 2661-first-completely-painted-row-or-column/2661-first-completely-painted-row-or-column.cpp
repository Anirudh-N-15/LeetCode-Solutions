class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int,int>> mp(rows*cols +1);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mp[mat[i][j]] = {i,j} ;
            }
        }

        vector<int> rowCount(rows);
        vector<int> colCount(cols);

        for(int i=0;i < rows*cols; ++i) {
            auto [row,col] = mp[arr[i]];
            rowCount[row]++ ;
            colCount[col]++ ;

            if(rowCount[row] >= cols){
                return i ;
            }
            else if(colCount[col] >= rows){
                return i ;
            }
        }
        return -1 ;
        
    }
};