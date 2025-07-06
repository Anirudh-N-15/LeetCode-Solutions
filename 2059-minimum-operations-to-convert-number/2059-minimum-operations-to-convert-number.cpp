//Use BFS while maintaining a vis array of size(1001). Process all the nodes in the
//queue for a level before going to the next one.

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int moves = 0;
        queue<int> q;
        q.push(start);
        vector<bool> vis(1001,0);

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int node = q.front();
                q.pop();

                if(node == goal) {
                    return moves ;
                }

                //We have to first process the negative and out of bound nodes
                //then only verify it, because that may be the answer sometimes.
                if(node > 1000 || node < 0 || vis[node]){
                    continue ;
                }
                vis[node] =1;

                for(int i=0;i<nums.size();i++) {
                    int a = node + nums[i], b = node - nums[i];
                    int c = node ^ nums[i];
                    for(auto num : {a,b,c}){
                        q.push(num);
                    }
                }
            }
            moves++ ;
        }
        return -1;
    }
};