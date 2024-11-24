class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long count = 0;
        long long  sum = 0 ;
        long long  minimum = INT_MAX ; 

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]<0){
                count++ ;
                }
            }
        }
            
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                sum += abs(matrix[i][j]) ;
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(minimum > abs(matrix[i][j])){
                    minimum = abs(matrix[i][j]);
                }
            }
        }

        return (count%2 == 0) ? sum : sum-(minimum*2);
        
    }
};