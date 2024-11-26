class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        int count = 0,ans ;

        for(int i=0;i<edges.size();++i){
            if(edges[i][1]>=0){
                indegree[edges[i][1]]++ ;
            }
        }
        for(int i=0;i<n;++i){
            if(indegree[i]==0){
                count++ ;
                ans = i ;
            }
        }

        return count > 1 ? -1 : ans ;
    }
};