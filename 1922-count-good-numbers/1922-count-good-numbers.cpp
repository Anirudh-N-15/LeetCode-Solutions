class Solution {
public:
   long long mod_pow(long long base, long long exp, long long mod)
     {
       if(exp == 0) return 1;                   
       long long res = mod_pow(base, exp/2, mod); 
       res = (res * res) % mod;                
       if(exp % 2 != 0)   
            res = (res * (base % mod)) % mod;
     return res;
     }
     int countGoodNumbers(long long n) {
        long long mod=1000000007LL, a;
        int ans;
        if( !(n%2))  a = mod_pow(5, n/2, mod);
        else         a = mod_pow(5, n/2+1, mod);
        long long b = mod_pow(4, n/2, mod);
        ans=(a*b)%mod;
        return ans;     
    }
};