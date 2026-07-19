/*Store the last occurence of the character and the compare the last char with the current character. If the character right now is lexicographically smaller than the last character of the string/stack and also the bigger character appears later, then we can pop the last char from the stack and replace it with the smaller character. Else we normally push the current character onto the stack */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size() ;
        vector<bool> vis(26,0) ;
        vector<int> last(26,0) ;
        string ans ;

        for(int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i ;
        }

        for(int i = 0; i < n; i++) {
            char ch = s[i] ;
            if(vis[ch - 'a']) {
                continue ;
            }

            while(!ans.empty() && ans.back() > ch && last[ans.back() - 'a'] > i ) {
                vis[ans.back() - 'a'] = false  ;
                ans.pop_back() ;
            }

            ans.push_back(ch) ;
            vis[ch - 'a'] = true ;
        }
        return ans ;
    }
};