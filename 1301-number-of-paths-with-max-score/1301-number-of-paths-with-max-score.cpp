class Solution {
public:
    const int MOD = 1e9 + 7;

    pair<int,int> dfs(int i,int j, vector<string>& board,vector<vector<pair<int,int>>>& dp ) {
        if(i < 0 || j < 0) return {-1, 0};

        if(board[i][j] == 'X') return {-1, 0};

        if(board[i][j] == 'E') return {0, 1};

        if(dp[i][j].first != -2) return dp[i][j];

        auto up = dfs(i-1, j, board, dp);
        auto left = dfs(i, j-1, board, dp);
        auto diag = dfs(i-1, j-1, board, dp);

        int best = max({up.first, left.first, diag.first});

        if(best == -1)
            return dp[i][j] = {-1, 0};

        int ways = 0;

        if(up.first == best)
            ways = (ways + up.second) % MOD;

        if(left.first == best)
            ways = (ways + left.second) % MOD;

        if(diag.first == best)
            ways = (ways + diag.second) % MOD;

        int val = 0;

        if(board[i][j] != 'S')
            val = board[i][j] - '0';

        return dp[i][j] = {best + val, ways};
    }


    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].size() ;

        vector<vector<pair<int,int>>> dp(m+1,vector<pair<int,int>>(n+1,{-2,-2}));

        auto ans = dfs(m-1,n-1,board,dp);

        if(ans.first == -1) return {0,0} ;

        return {ans.first,ans.second} ;
    }
};