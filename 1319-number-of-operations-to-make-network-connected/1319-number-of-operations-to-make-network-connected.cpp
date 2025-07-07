class DisjointSetUnion {
public:
    vector<int> parent,rank;
    DisjointSetUnion(int n) {
        parent.resize(n), rank.resize(n,0);
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int node) {
        //Path compression is done
        if(node != parent[node]) {
            return parent[node] = findParent(parent[node]);
        }
        return node;
    }

    void unionByRank(int u ,int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv ;
        } else if(rank[pv] < rank[pu]) {
            parent[pv] = pu ;
        } else {
            parent[pv] = pu ;
            rank[pu]++ ;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n - 1) return -1 ;
        DisjointSetUnion dsu(n);

        for(int i=0;i<m;i++) {
            int u = connections[i][0], v = connections[i][1] ;
            dsu.unionByRank(u,v);
        }

        //The number of disconnected computers will be count - 1
        int count = 0;
        for(int i=0;i<n;i++) {
            if(dsu.findParent(i) == i){
                count++ ;
            }
        }
        return count -1;

    }
};