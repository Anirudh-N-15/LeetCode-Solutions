class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxones = 0;

        for(int i=0;i<32;++i){
            int ones =0 ;
            for(int num : candidates){
                if(num & (1 << i)){
                    ones++ ;
                }
            }
            maxones = max(maxones,ones);
        }
        return maxones ;
    }
};