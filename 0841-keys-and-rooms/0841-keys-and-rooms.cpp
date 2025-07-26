class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis,int node) {
        vis[node] = true ;

        for(const auto &adjNode : rooms[node]) {
            if(!vis[adjNode]) {
                dfs(rooms,vis,adjNode);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,0);

        dfs(rooms,vis,0);

        for(const auto& num : vis) {
            if(num != 1) {
                return false ;
            }
        }
        return true ;
    }
};