class Solution {
public:

    optional<int> solveSubgraph(int n, vector<int>& nodes, vector<vector<int>>& adjlist){
        int ans = -1;
        for (auto root: nodes){
            constexpr int inf = 1e9;
            vector<int> dist(n, inf);
            dist[root] = 0;
            
            queue<int> q;
            q.emplace(root);

            bool valid = true;
            int maxDist = 0;
            while (!q.empty() && valid){
                int u = q.front();
                q.pop();
                maxDist = max(maxDist, dist[u]);

                for (auto v: adjlist[u]){
                    if (dist[v] != inf && dist[v] != dist[u] - 1 && dist[v] != dist[u]+1){
                        valid = false;
                        break;
                    }
                    else if (dist[v] > dist[u]+1){
                        dist[v] = dist[u] + 1;
                        q.emplace(v);
                    }
                }
            }

            if (valid) ans = max(ans, maxDist);
        }

        if (ans > -1) return ans + 1;
        else return nullopt;
    }


    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n, vector<int>());
        int e = edges.size(); 
        for (int i=0; i<e; i++){
            adjlist[edges[i][0]-1].emplace_back(edges[i][1]-1);
            adjlist[edges[i][1]-1].emplace_back(edges[i][0]-1);
        }

        int ans = 0;
        vector<int> visited(n, 0);
        queue<int> q;
        vector<int> cc;
        for (int i=0; i<n; i++){
            if (!visited[i]){
                visited[i] = 1;
                q.emplace(i);
                while (!q.empty()){
                    int u = q.front();
                    q.pop();
                    cc.emplace_back(u);

                    for (auto v: adjlist[u]){
                        if (!visited[v]){
                            visited[v] = 1;
                            q.emplace(v);
                        }
                    }
                }

                optional<int> res = solveSubgraph(n, cc, adjlist);
                if (res) ans += res.value();
                else return -1;
                
                cc.clear();
            }
        }

        
        return ans;
    }
};