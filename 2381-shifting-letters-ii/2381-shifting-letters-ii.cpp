class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> finalShift(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], dir = shift[2] ;
            int val = (dir == 1) ? 1 : -1 ;
            finalShift[start] += val ;
            if( end +1 < n) {
                finalShift[end +1] -= val ;
            }
        }

        int total_shift = 0 ;
        for(int i=0;i<n;++i) {
            total_shift += finalShift[i] ;
            int amt = ((total_shift % 26) + 26) % 26 ;
            s[i] = 'a' + (s[i] - 'a' + amt) % 26 ;
        }

        return s ;
    }
};