class DisjointSetUnion {
public:
    vector<int> rank, parent;
    DisjointSetUnion(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v){
            return;
        } else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v ;
        } else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u ;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++ ;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        using t= tuple<int,int,int> ;
        vector<t> edges;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost,i,j});
            }
        }

        sort(edges.begin(),edges.end());
        DisjointSetUnion dsu(n) ;
        int ans =0;

        for(auto &[cost, u, v] : edges){
            if(dsu.findUPar(u) != dsu.findUPar(v)){
                dsu.unionByRank(u, v);
                ans += cost;
            }
        }
        return ans;
    }
};