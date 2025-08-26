class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ansArea =0;
        float maxDiagonal =0;

        for(const auto & dim : dimensions) {
            int l = dim[0], b = dim[1] ;
            float diag = l*l + b*b;
            int area = l * b;
            if(diag >= maxDiagonal) {
                ansArea = max(area,ansArea) ;
                maxDiagonal = max(maxDiagonal,diag) ;
            }
        }
        return ansArea ;
    }
};