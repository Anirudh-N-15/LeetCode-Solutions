class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n =arr.size();
        int count = 0 ;
        int sum = 0 ;

        for(int i=0;i<n;++i){
            sum += arr[i] ;
            int formulasum = (i*(i+1))/2 ;
            if(sum == formulasum){
                count++ ;
            }
        }
        return count ;
    }
};