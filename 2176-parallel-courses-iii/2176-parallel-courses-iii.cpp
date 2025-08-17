class Solution {
public:
    vector<int> memo;

    int dfs(int node, vector<int>&time, vector<vector<int>>& adjList) {
        if(memo[node] != -1) return memo[node] ;

        if(adjList[node].size() == 0) {
            return time[node] ;
        }

        int ans =0;
        for(auto neigh : adjList[node]) {
            ans = max(ans,dfs(neigh,time,adjList));
        }
        return memo[node] = time[node] + ans ;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int edges = relations.size();
        vector<vector<int>> adjList(n);
        memo.assign(n,-1);

        for(const auto &rel : relations) {
            int u = rel[0] -1, v = rel[1]- 1;
            adjList[u].push_back(v);
        }      

        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans,dfs(i,time,adjList));
        }
        return ans ;
    }
};