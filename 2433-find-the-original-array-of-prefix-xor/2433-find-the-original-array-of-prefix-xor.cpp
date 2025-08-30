class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n) ;
        ans[0]= pref[0];

        for(int i=1;i<n;i++) {
            int temp = pref[i] ^ pref[i-1] ;
            ans[i] = temp ;
        }
        return ans ;
    }
};