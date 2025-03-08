class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = 100;
        int ok = 0;
        if(n == k){
            for(int i=0;i<n;++i){
                if(blocks[i] == 'W'){
                   ok++ ; 
                }
            }
            return ok ;
        }
        for(int i=0;i<=(n-k);++i){
            int count = 0;
            for(int j=i;j<(k+i);++j){
                if(blocks[j] == 'W'){
                    count++ ;
                }
            }
                ans = min(ans,count);
        }
        return ans ;
    }
};