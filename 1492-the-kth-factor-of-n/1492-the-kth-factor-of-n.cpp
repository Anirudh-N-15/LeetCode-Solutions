class Solution {
public:
    int kthFactor(int n, int k) {
        priority_queue<int, vector<int>> pq;

        for(int i=n;i>=1;--i){
            if(n % i == 0){
                pq.push(i);
            }
        }
        int m = pq.size() - k ;
        int ans = 0;
        for(int i =m;i>=0;--i ){
            ans = pq.top();
            pq.pop();
        }
        return ans == 0 ? -1 : ans  ;
    }
};