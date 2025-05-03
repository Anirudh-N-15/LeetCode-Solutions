class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const int n = tops.size();
        vector<int> freqT(7,0) ;
        vector<int> freqB(7,0) ;
        vector<int> freqEq(7,0);

        for(int i=0;i<n;++i){
            int t= tops[i], b = bottoms[i];
            freqT[t]++ ;
            freqB[b]++ ;
            if(t == b)
                freqEq[t]++ ;
        }
        int ans = INT_MAX ;
        for(int i=1; i < 7; ++i){
            int t = freqT[i], b = freqB[i];
            if(t + b - freqEq[i] == n) {
                ans = min(ans, min(n -t, n-b));
            }
        }
        return ans == INT_MAX ? -1: ans ;
    }
};