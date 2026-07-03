class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size() ;
        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n,0);

        int lo = INT_MAX;
        int hi = 0;

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(u!=0 && !online[u]) continue;
            if(v!=n-1 && !online[v]) continue;

            graph[u].push_back({v,w});
            indegree[v]++;

            lo = min(lo,w);
            hi = max(hi,w);
        }

        if(lo==INT_MAX) return -1;

        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indegree[i]==0) q.push(i);
        }
            
        vector<int> topo;

        while(!q.empty()){

            int u=q.front();
            q.pop();

            topo.push_back(u);

            for(auto &[v,w]:graph[u]){

                indegree[v]--;

                if(indegree[v]==0)
                    q.push(v);
            }
        }

        auto check = [&](int limit){

            const long long INF = 4e18;

            vector<long long> dist(n,INF);

            dist[0]=0;

            for(int u:topo){

                if(dist[u]==INF)
                    continue;

                for(auto &[v,w]:graph[u]){

                    if(w<limit)
                        continue;

                    dist[v]=min(dist[v],dist[u]+w);
                }
            }

            return dist[n-1]<=k;
        };

        if(!check(lo))
            return -1;

        while(lo<=hi){

            int mid = lo+(hi-lo)/2;

            if(check(mid))
                lo=mid+1;
            else
                hi=mid-1;
        }
        return hi;
    }
};