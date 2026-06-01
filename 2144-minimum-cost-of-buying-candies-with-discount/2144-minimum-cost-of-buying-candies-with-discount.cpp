class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size() ;
        sort(cost.begin(),cost.end());
        int ans = 0,count = 0;

        for(int i=n-1; i >= 0; i--) {
            if(count == 2) {
                count = 0;
                continue ;
            }
            ans += cost[i] ;
            count++ ;
        }
        return ans ;
    }
};