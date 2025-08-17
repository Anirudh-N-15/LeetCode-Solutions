// class DisjointSetUnion {
// public:
//     vector<int> parent;
//     vector<int> rank ;

//     DisjointSetUnion(int n) {
//         parent.resize(n);
//         rank.resize(n,0);

//         for(int i=0;i<n;i++) {
//             parent[i] = i;
//         }
//     }

//     int findParent(int node) {
//         if(node == parent[node]) {
//             return node ;
//         } else {
//             return parent[node] = findParent(parent[node]);
//         }
//     }

//     void unionByRank(int u, int v){ 
//         int ulp_u = findParent(u);
//         int ulp_v = findParent(v);

//         if(ulp_u == ulp_v) {
//             return ;
//         }
//         if(rank[ulp_v] < rank[ulp_u]) {
//             parent[ulp_v] = ulp_u ;
        
//         }else if(rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v ;
//         } else {
//             parent[ulp_u] = ulp_v ;
//             rank[ulp_v]++ ;
//         }
//     }
// };

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        vector<int> ans ;
        for(auto it : edges) {
            int u = it[0] , v = it[1] ;
            indegree[v]++ ;
        }

        for(int i=0;i<n;i++) {
            if(indegree[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans ;
    }
};