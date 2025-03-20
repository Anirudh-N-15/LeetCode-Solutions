class Solution {
public:
    vector<int> parent;
    vector<int> depth;


    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n,-1);
        depth.resize(n,0);
        vector<unsigned int> componentCost(n,-1); //unsigned int on -1 goes to INT_MAX

        for(auto & edge : edges){
            Union(edge[0],edge[1]);
        }

        for(auto &edge : edges){
            int root = find(edge[0]);
            componentCost[root] &= edge[2];
        }

        vector<int> ans ;

        for(auto &que : query){
            if(find(que[0]) != find(que[1])){
                ans.push_back(-1);
            }
            else{
                int root = find(que[0]) ;
                ans.push_back(componentCost[root]);
            }
        }
        return ans ;

    }
private:
    int find(int node){
        if(parent[node] == -1) return node;

        return parent[node] = find(parent[node]);
    }
private:
    void Union(int node1, int node2){
        int root1 = find(node1);
        int root2 = find(node2);

        if(root1 == root2) return;

        if(depth[root1] < depth[root2]) swap(root1, root2);

        parent[root2] = root1;

        if(depth[root1] == depth[root2]) depth[root1]++ ;
    }

};

//In a walk both edges and vertices can be repeates unlike a path
//To efficiently find and process the connected components of the graph, we use the Disjoint Set (Union-Find) ds.Two operations are done i.e Union and find.


