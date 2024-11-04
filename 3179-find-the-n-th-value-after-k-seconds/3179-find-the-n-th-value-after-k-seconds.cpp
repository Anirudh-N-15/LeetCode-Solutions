class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<long long> arr(n,1);

        for(int i=1;i<=k;++i){
           for(int j=1;j<n;++j){
            arr[j] = (arr[j] + arr[j-1])% 1000000007;
           } 
        }

        return arr[n-1] % 1000000007 ;
    }
};