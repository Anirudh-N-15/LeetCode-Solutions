class DisjointSetUnion {
public:
    vector<int> parent, rank;
    DisjointSetUnion(int n) {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) {
            return node ;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if(ult_u == ult_v) return ;

        if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v ;
        }
        else if(rank[ult_v] < rank[ult_u]) {
            parent[ult_v] = ult_u;
        } else {
            parent[ult_v] = ult_u;
            rank[ult_u]++ ;
        }
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSetUnion dsu(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j] == 1 && i != j){
                    dsu.unionByRank(i+1,j+1);
                }
            }
        }

        int count = 0;
        //Using 1- based indexing
        for(int i=1;i<=n;i++) { 
            if(dsu.findParent(i) == i){
                count++ ;
            }
        }
        return count ;
    }
};