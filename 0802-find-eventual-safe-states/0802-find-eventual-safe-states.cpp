class Solution {
public:
    int helper(vector<vector<int>>& graph, int curr, vector<int>& visited)
    {
        if(visited[curr] != 2)
            return visited[curr];
        if (graph[curr].size() == 0)
            return visited[curr] = 1;
        int res = 1;
        visited[curr] = 3;
        for(auto v : graph[curr])
        {
            if(visited[v] == 3)
                res = 0;
            else
                res &= helper(graph, v, visited);
        }
        return visited[curr] = res;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> pow(n, 2);
        for(int i = 0 ; i < n ; ++i) {
            helper(graph, i, pow);
        }
        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(pow[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};