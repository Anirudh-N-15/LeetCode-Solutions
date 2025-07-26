class Solution {
public:
    string removeStars(string s) {
        stack<char> st ;

        for(const char &ch : s) {
            if(!st.empty() && ch == '*') {
                st.pop() ;
                continue; 
            }
            st.push(ch);
        }

        string ans = "" ;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};