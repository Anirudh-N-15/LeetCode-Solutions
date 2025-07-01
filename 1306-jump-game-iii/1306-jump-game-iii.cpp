class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(start) ;

        while(!q.empty()) {
            int index = q.front();
            q.pop();

            if(arr[index] == 0) {
                return true ;
            }
            
            if(!vis[index]) {
                if(index + arr[index] < n) {
                    vis[index] = 1;
                    q.push(index + arr[index]);
                }
                if(index - arr[index] >= 0) {
                    vis[index] =1;
                    q.push(index - arr[index]);
                }
            }
        }
        return false ;
    }
};