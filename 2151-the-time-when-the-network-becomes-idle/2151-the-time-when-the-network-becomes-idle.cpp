class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adjList(n);

        for(auto &edge : edges) {
            int u = edge[0], v = edge[1] ;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> dist(n,1e6);
        vector<int> vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[0] = 0;
        vis[0] = true ;
        pq.push({0,0});
        
        while(!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            for(auto adjNode : adjList[node]) {
                if(currDist + 1 < dist[adjNode] && !vis[adjNode]) {
                    dist[adjNode] = 1+ currDist;
                    vis[adjNode] = true ;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        int idleTime = 0;
        for(int i=1;i<n;i++) {
            int firstMsgRecieve = dist[i]* 2;
            int numExtraMsg = (firstMsgRecieve -1)/patience[i] ;
            int lastMsgSent=numExtraMsg * patience[i];
            int lastMsgRecieve = lastMsgSent + firstMsgRecieve;
            idleTime = max(idleTime,lastMsgRecieve);
        }
        return idleTime+1 ;
    }
};