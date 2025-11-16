class Solution {
public:
    int numSub(string s) {
        int mod = 1000000007 ;
        int n = s.size();
        long long ans = 0;

        for(int i=0;i<n;i++) {
            long long count = 0;
            while(i < n && s[i] == '1') {
                count++ ;
                i++ ;
            }
            
            ans = (ans % mod) + (((count % mod)*(count+1) % mod)/2)%mod ;
        }
        return ans % mod  ;
    }
};