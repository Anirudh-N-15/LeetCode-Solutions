class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();

        while(s.find(part) != string::npos) {
            int p = s.find(part);
            s.erase(p,m);
        }
        return s ;
    }
};