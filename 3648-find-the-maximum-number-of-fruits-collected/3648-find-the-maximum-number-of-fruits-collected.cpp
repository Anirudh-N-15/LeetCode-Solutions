class Solution {
public:
    int n;
    vector<vector<int>> memo ;

    int dfs2(int row, int col, vector<vector<int>>& fruits) {
        if(row < 0 || col < 0 || row >= n || col >= n) {
            return 0;
        }
        if(memo[row][col] != -1) return memo[row][col] ;

        int val = fruits[row][col];
        int ans = 0;

        if(row == col) {
            ans = max(ans,dfs2(row+1,col+1,fruits));
        } else if(row == col -1) {
            ans = max({ans,
                      dfs2(row+1,col+1,fruits),
                      dfs2(row+1,col,fruits)});
        } else {
            ans = max({ans,
                       dfs2(row + 1, col + 1, fruits),
                       dfs2(row + 1, col, fruits),
                       dfs2(row + 1, col - 1, fruits)});
        }
        return memo[row][col] = val + ans ;
    }

    int dfs3(int row, int col, vector<vector<int>>& fruits) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;

        if(memo[row][col] != -1){return memo[row][col];}
        
        int val = fruits[row][col];
        int ans = 0;

        if (row == col) {
            ans = max(ans, dfs3(row + 1, col + 1, fruits));
        }
        else if (row - 1 == col) {
            ans = max({ans,
                       dfs3(row + 1, col + 1, fruits),
                       dfs3(row, col + 1, fruits)});
        }
        else {
            ans = max({ans,
                       dfs3(row + 1, col + 1, fruits),
                       dfs3(row, col + 1, fruits),
                       dfs3(row - 1, col + 1, fruits)});
        }
        
        return memo[row][col] = val + ans;
    }



    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        memo = vector<vector<int>> (n,vector<int>(n,-1));

        int ans = 0;

        for(int i=0;i<n;i++) {
            ans += fruits[i][i] ;
            fruits[i][i] = 0;   //marking visited 
        }

        ans += dfs2(0,n-1,fruits); //child 2
        ans += dfs3(n-1,0,fruits); //child 3

        return ans ;
    }
};