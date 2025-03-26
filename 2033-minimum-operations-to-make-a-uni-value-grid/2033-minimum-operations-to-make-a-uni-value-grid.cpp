class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        vector<int> linear;
        int result = INT_MAX ;


        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] % x != grid[0][0] % x) return - 1;
                linear.push_back(grid[i][j]);
            }
        }
        sort(linear.begin(),linear.end());
        n = linear.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);

        for(int i=1;i<n;++i){
            prefix[i] = prefix[i -1] + linear[i -1] ;
        }

        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i +1] + linear[i + 1];
        }

        for(int i=0;i<n;++i){
            int left = (linear[i] * i - prefix[i]) / x ;
            int right = (suffix[i] - linear[i] *  (n - i - 1)) / x ;
            result = min(result, left + right) ;
        }

        return result ;
    }
};