class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj,int k) {
        int n = adj.size();
        vector<int> target(n);
        
        for(int i=0;i<n;++i) {
            int count = 0;
            queue<pair<int,int>> q; // depth, node
            vector<bool> visited(n,0);
            visited[i] = 1;
            q.push({0,i});

            while(!q.empty()) {
                auto it = q.front();
                q.pop();

                int depth = it.first ;
                int node =  it.second ;

                if(depth > k) continue ;

                count++ ;

                for(auto &adjnode : adj[node]) {
                    if(!visited[adjnode]) {
                        visited[adjnode] = 1;
                        q.push({depth + 1,adjnode});
                    }
                }
            }
            target[i] = count ;
        }
        return target ;
    }


    vector<vector<int>> buildAdj(vector<vector<int>>& edges,int n) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges) {
            int u = edge[0], v = edge[1] ;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);  
        }
        return adj ;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k){
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1 = buildAdj(edges1,n);
        vector<vector<int>> adj2 = buildAdj(edges2,m);

        vector<int> target1 = bfs(adj1,k);
        vector<int> target2 = bfs(adj2,k-1); //k-1 since 1 node is consumed from tree1 

        int tree2Target = 0;
        for(auto &it : target2) {
            tree2Target = max(tree2Target,it);
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++) {
            ans[i] = target1[i] + tree2Target ;
        }
        return ans ;
    }
};