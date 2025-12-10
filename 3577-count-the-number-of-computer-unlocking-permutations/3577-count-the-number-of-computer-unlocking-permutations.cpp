class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int mod = 1e9 + 7;
        map<int,int> mp ;
        for(const int &num : complexity ) {
            mp[num]++ ;
        }
        if(mp.begin()->second != 1 || mp.begin()->first != complexity[0]) return 0 ;

        int n = complexity.size() - 1;
        long long ans = 1;
        for(int i=1;i<=n;i++) {
            ans = ((ans % mod) * (i%mod))% mod ;
        }
        return ans%mod ;
    }
};