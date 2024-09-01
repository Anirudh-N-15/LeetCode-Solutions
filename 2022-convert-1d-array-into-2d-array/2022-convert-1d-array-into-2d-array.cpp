class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size())
        return {}; 
        vector<vector<int>> result(m,vector<int>(n)) ;

        for(int i=0;i<m;++i){
            for(auto j=0;j<n;++j){
                result[i][j] = original[i*n + j] ;
            }
        }

        return result ;
    }
};