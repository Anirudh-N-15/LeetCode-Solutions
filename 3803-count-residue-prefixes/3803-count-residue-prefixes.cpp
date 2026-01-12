class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> st ;
        int count = 0;
        int current = 0;
        for(const char &ch : s) {
            st.insert(ch) ;
            current++ ;
            if(st.size() == current % 3) {
                count++ ;
            }
        }
        return count ;
    }
};