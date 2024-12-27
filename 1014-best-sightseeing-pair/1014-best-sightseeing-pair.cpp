class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxPrev = values[0],currMax = values[0] + values[1]-1 ;

        for(int i=1;i<n;++i){
            currMax = max(currMax,values[i]-i+maxPrev);
            maxPrev = max(maxPrev,values[i]+i);
        }
        return currMax ;
    }
};