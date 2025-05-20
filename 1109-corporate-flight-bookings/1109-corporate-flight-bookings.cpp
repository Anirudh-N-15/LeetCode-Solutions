class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m = bookings.size();
        vector<int> ans(n+2,0);

        for(int i=0;i<m;++i) {
            int l = bookings[i][0],r = bookings[i][1], val = bookings[i][2] ;
            ans[l] += val ;
            ans[r+1] -= val ;  
        }
        for(auto &num : ans) {
            cout << num << " " ;
        }
        for(int i=1;i<=n;++i) {
            ans[i] = ans[i] + ans[i-1] ;
        }
        ans.erase(ans.begin(),ans.begin()+1);
        ans.erase(ans.end());
        return ans ;
    }
};