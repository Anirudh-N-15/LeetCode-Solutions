class Solution {
public:
    int minOperations(int n) {
        int arr[n];
        int sum =0;

        for(int i=0;i<n;++i){
            if(i%2==1){
                sum += (n-i) ;
            }
        }    
        return sum  ;  
    }
};