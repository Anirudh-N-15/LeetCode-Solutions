class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        int ans = 0;
        vector<int> visited(n,0); //We use int bcoz 0 denotes box not reachable,
                                  //1 denotes box is reachable and 
                                  //2 denotes box is reachable and has been opened

        for(const int &i : initialBoxes) {
            q.push(i) ; //Push all the boxes in the queue that is reachable first
        }

        while(!q.empty()) {
            int currBox = q.front() ;
            q.pop() ;

            if(visited[currBox] == 2){
                continue ; //Box is reachable but has already been opened
            }else if(status[currBox] == 1) {
                visited[currBox] = 2;
            } else {
                visited[currBox] = 1;
                continue ;
            }
            ans += candies[currBox] ; //Add the number of candies in CurrBox to our answer

            for(const int& key : keys[currBox]) {
                status[key] = 1;
                if(visited[key] == 1){
                    q.push(key);
                }
            }   

            for(const int& containedBox : containedBoxes[currBox]) {
                if(visited[containedBox]){
                    continue ;
                }
                q.push(containedBox);
            }
        }
        return ans ;
    }
};