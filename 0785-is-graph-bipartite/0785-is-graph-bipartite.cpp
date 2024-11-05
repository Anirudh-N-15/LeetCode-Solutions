class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> color(n,-1);

        for(int i=0;i<n;++i){
            if(color[i]== -1){
                if(!isBipartiteBFS(graph,color,i)){
                    return false ;
                }
            }
        }
        return true ;
    }
private:
    bool isBipartiteBFS(vector<vector<int>> graph,vector<int>& color,int start){
        int n = graph.size();
        queue<int> q ;
        q.push(start);
        color[start] = 0 ;

        while(!q.empty()){
            int current = q.front();
            q.pop() ;

            for(int i: graph[current]){
                    if(color[i]== -1){
                        color[i] = 1- color[current];
                        q.push(i);
                    }
                    else if(color[i]==color[current]){
                        return false ;
                    }
            }
        }
        return true ;
    }
};