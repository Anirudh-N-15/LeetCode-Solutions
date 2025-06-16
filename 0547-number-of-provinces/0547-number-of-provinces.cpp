class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        visited[node] = 1;

        for(auto it :adj[node]) {
            if(!visited[it]) {
                dfs(adj,visited,it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n,0);
        int ans = 0;

        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(adj,visited,i);
                ans++ ;
            }
        }

        return ans ;
    }
};