class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color,int parent,int node) {
        if(parent == -1) {
            color[node] = 0;
        }
        if(parent != -1 &&color[node] == -1) {
            color[node] = !color[parent] ;
        } else {
            if(parent != -1 && color[node] == color[parent]) {
                return false ;
            }
        }
        
        for(auto it : graph[node]) {
            if(color[it] == -1) {
                if(!dfs(graph,color,node,it)) return false ;
            } else if(color[it] == color[node]) {
                return false ;
            }
        }
        return true ;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++) {
            if(color[i] == -1) {
                if(dfs(graph,color,-1,i) == false) {
                    return false ;
                }
            }
        }
        return true ;
    }
};