class Solution {
public:
    int dfs( vector<vector<int>>& adjList,int node, int parent) {
        int maxDepth = 0;

        for (int neigh : adjList[node]) {
            if (neigh == parent) continue;

            maxDepth = max(maxDepth,1 + dfs(adjList, neigh, node));
        }
        return maxDepth;
    }

    long long modPow(long long base, long long exp, long long mod) {
        long long res = 1;

        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % mod;

            base = (base * base) % mod;
            exp >>= 1;
        }

        return res;
    }


    int assignEdgeWeights(vector<vector<int>>& edges) {
        int num = 0;
        const int mod = 1e9 + 7 ;
        for (int i = 0; i < edges.size(); i++) {
            for (int j = 0; j < 2; j++) {
                num = max(num,edges[i][j]);
            }
        }
        vector<vector<int>> adjList(num+1);
        vector<int> vis(num+1,0);

        for(const auto &edge : edges) {
            int u = edge[0], v = edge[1] ;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int ans = dfs(adjList,1,-1);

        int res = modPow(2,ans-1,mod) % mod ;

        return res ;
    }
};