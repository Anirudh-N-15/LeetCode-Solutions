class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        vector<int> alphabets(27,0);
        int reverseIndex = 26 ;
        for(int i=1;i<=26;i++) {
            alphabets[i] = reverseIndex ;
            reverseIndex-- ;
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += (alphabets[s[i] - 'a' + 1] * (i+1)) ;
        }
        return ans ;
    }
};