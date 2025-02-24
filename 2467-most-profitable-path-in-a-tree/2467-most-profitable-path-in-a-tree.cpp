class Solution {
    bool harsh(int curr, int parent, vector<int>& path,
               vector<vector<int>>& edges) {
        if (curr == 0) {
            path.push_back(curr);
            return true;
        }

        for (auto& x : edges[curr]) {
            if (x != parent) {
                if (harsh(x, curr, path, edges)) {
                    path.push_back(curr);
                    return true;
                }
            }
        }

        return false;
    }

    void dfs(int curr, int parent, vector<int>& amount,
             vector<vector<int>>& edges) {
        int mx = INT_MIN;
        for (auto& x : edges[curr]) {
            if (x != parent) {
                dfs(x, curr, amount, edges);
                mx = max(mx, amount[x]);
            }
        }

        if (mx != INT_MIN) {
            amount[curr] += mx;
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& a, int bob,
                           vector<int>& amount) {
        int n = a.size() + 1;
        vector<vector<int>> edges(n);

        for (int i = 0; i < n - 1; i++) {
            int u = a[i][0], v = a[i][1];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vector<int> path;

        harsh(bob, -1, path, edges);

        reverse(path.begin(), path.end());

        int d = path.size() / 2;

        for (int i = 0; i <= d; i++) {
            if (i == d) {
                if (path.size() % 2) {
                    amount[path[i]] /= 2;
                    continue;
                } else
                    continue;
            }

            amount[path[i]] = 0;
        }

        dfs(0, -1, amount, edges);

        return amount[0];
    }
};