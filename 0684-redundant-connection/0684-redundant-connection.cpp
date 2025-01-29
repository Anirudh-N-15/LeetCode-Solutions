class Solution {
public:
    int n;
    void addEdge(int x, int y, vector<int> & parent, vector<int> & rank) {

        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            rank[x] = rank[parent[x]] +1;
            x = parent[x]; 
        }
        while (y != parent[y]) {
            parent[y] = parent[parent[y]];
            rank[y] = rank[parent[y]] +1;
            y = parent[y]; 
        }
        if (rank[x] <= rank[y]) {
            parent[x] = y;
            rank[x] = rank[y] + 1;
        } else {
            parent[y] = x;
            rank[y] = rank[x] + 1;
        }
    }
    bool isSameParent(int x, int y, vector<int> & parent) {
        while (x != parent[x]) {
            x = parent[x];
        }
        while (y != parent[y]) {
            y = parent[y];
        }
        if (x == y) {
            return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<int> parent(n+1);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }
        vector<int> rank(n+1, 0);
        for (int i = 0; i < n-1; i ++) {
            if (isSameParent(edges[i][0], edges[i][1], parent)) {
                return edges[i];
            }
            addEdge(edges[i][0], edges[i][1], parent, rank);
        }
        return edges[n-1];
    }
};