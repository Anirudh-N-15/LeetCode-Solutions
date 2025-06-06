class Solution {
public:
    string robotWithString(string s) {
        vector<int> count(26,0);
        for(const char &c : s){
            count[c - 'a']++ ;
        }
        string ans = "";
        stack<char> st;
        for(const char &c : s){
            count[c - 'a']-- ;
            st.push(c);
            int i;
            for(i=0;i<26;++i) {
                if(count[i]>0){
                    break;
                }
            }
            char smallest = 'a' + i;
            while(!st.empty() && st.top() <= smallest) {
                ans += st.top();
                st.pop();
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans ;
    }
};