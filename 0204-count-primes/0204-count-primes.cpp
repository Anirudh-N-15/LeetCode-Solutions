class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        memset(prime,true,n+1);
        int count =0 ;

        for(int i=2;i*i <=n;++i){

            if(prime[i]== true){

                for(int j=i*i;j<=n;j+=i){
                    prime[j] = false ;
                }
            }
        }

        for(int i=2;i<n+1;++i){
            if(prime[i]==true){
                count++ ;
            }
        }
        return count ;
    }
};