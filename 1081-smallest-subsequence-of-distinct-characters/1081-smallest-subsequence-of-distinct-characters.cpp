class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<bool> vis(26, 0);
        vector<int> last(26, 0);
        string st;

        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (vis[ch - 'a']) {
                continue;
            }

            while (!st.empty() && st.back() > ch && last[st.back() - 'a'] > i) {
                vis[st.back() - 'a'] = false ;
                st.pop_back();
            }
            st.push_back(ch);
            vis[ch - 'a'] = true ;
        }

        return st;
    }
};