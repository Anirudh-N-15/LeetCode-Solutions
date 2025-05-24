class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> containsChar;

        for(int i=0;i<n;++i) {
            for(const char &c : words[i]) {
                if(c == x) {
                    containsChar.push_back(i);
                    break;
                }
            }
        }
        return containsChar ;
    }
};