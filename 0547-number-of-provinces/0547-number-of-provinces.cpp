class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <int> visited(isConnected.size(),0);
        int count = 0 ;

        for(int i=0;i<isConnected.size();++i){
            if(!visited[i]){
                count++ ;
                DFS(isConnected,i,visited);
            }
        }
        return count ;
    }

private:
    void DFS(vector<vector<int>>isConnected,int startvertex,vector<int>& visited){
        visited[startvertex] =1 ;

        for(int i=0;i<visited.size();++i){
            if(isConnected[startvertex][i]==1 && visited[i]==0)
            DFS(isConnected,i,visited);
        }
    }    
};