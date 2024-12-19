class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n =arr.size();
        vector<int> runsum(n);
        vector<int> actualsum(n);

        for(int i =0;i<n;++i){
            runsum[i] = arr[i];
            actualsum[i] = i;
        }
        for(int i=1;i<n;++i){
            runsum[i] = runsum[i] + runsum[i-1]; 
        }
        for(int i=1;i<n;++i){
            actualsum[i] = actualsum[i] + actualsum[i-1];
        }

        int count = 0 ;

        for(int i=0;i<n;++i){
            if(actualsum[i]==runsum[i]){
                count++ ;
            }
        }
        return count ;
    }
};