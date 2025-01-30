class Solution {
public:
    int bfs(int node, vector<vector<int>>& adj, int n) {
        int count = 0;
        queue<int> q;
        q.push(node);
        vector<int> vis(n, 0);
        vis[node] = 1;
        while (!q.empty()) {
            int siz = q.size();
            count++;
            for (int i = 0; i < siz; i++) {
                int curr = q.front();
                q.pop();
                for (auto it : adj[curr]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
        return count;
    }
    bool isBipartite(int i, vector<vector<int>>& adj, vector<int>& vis, int n,
                     vector<int>& comp) {
        queue<int> q;
        q.push(i);
        vis[i] = 0;
        while (!q.empty()) {
            int curr = q.front();
            comp.push_back(curr);
            q.pop();
            for (auto it : adj[curr]) {
                if (vis[it] == -1) {
                    vis[it] = !vis[curr];
                    q.push(it);
                } else if (vis[it] == vis[curr])
                    return 0;
            }
        }
        return 1;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& x : edges) {
            adj[x[0] - 1].push_back(x[1] - 1);
            adj[x[1] - 1].push_back(x[0] - 1);
        }
        int maxi = 0;
        vector<int> col(n, -1);
        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {
                vector<int> comp;
                bool check = isBipartite(i, adj, col, n, comp);
                if (check == 0)
                    return -1;
                int maxi2 = 0;
                for (auto x : comp) {
                    int val = bfs(x, adj, n);
                    maxi2 = max(maxi2, val);
                }
                maxi += maxi2;
            }
        }
        return maxi;
    }
};