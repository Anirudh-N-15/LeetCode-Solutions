class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        unordered_set<char> st ;
        for(const char &ch : word) {
            st.insert(ch);
        }

        for(const char &ch : st) {
            if(islower(ch)) {
                cout << ch << endl ;
                if(st.find(toupper(ch)) != st.end()) {
                    count++ ;
                }
            }
        }
        return count ;
    }
};