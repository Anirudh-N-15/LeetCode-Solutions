class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> ans ;
        int count =0;

        //Just reverse the order of creating the adj list
        for(auto &it : graph) {
            adj[it[1]].push_back(it[0]);
        }

        for(auto &it : adj) {
            for(const int &node : it) {
                indegree[node]++ ;
            }
        }

        for(int i=0;i<n;i++) {
            if(indegree[i] == 0) {
                q.push(i) ;
            }
        }

        //The queue already contains at least one node with indegree 0
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++ ;

            for(auto &it : adj[node]) {
                indegree[it]-- ;
                if(indegree[it] == 0) {
                    q.push(it);
                    count++ ;
                }
            }
        }
        if(count < n) return {} ;

        return ans ;
    }
};