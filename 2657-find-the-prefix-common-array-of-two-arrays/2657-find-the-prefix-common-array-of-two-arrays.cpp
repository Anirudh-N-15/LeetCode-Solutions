class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size() ;
        vector<int> count(51,0) ;
        vector<int> ans(n);

        for(int i=0;i<n;++i) {
            int j=0;
            int freq=0;
            count[A[i]]++ ;
            count[B[i]]++ ;
            while(j < 51) {
                if(count[j] ==2){
                    freq++ ;
                }
                j++ ;
            }
            ans[i] = freq ;
        }
        return ans ;
    }
};