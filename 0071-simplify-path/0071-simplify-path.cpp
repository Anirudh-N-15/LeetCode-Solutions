class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st ;
        string res = "";
        int n = path.size();

        for(int i=0;i<n;i++) {
            if(path[i] == '/') continue ;

            string temp = "";

            while(i < n && path[i] != '/') {
                temp += path[i] ;
                i++ ;
            }

            if(temp == ".") continue ;

            else if(temp == "..") {
                if(!st.empty()) {
                    st.pop() ;
                }
            } else {
                st.push(temp) ;
            }
        }

        while(!st.empty()) {
            res = "/" + st.top() + res ; //This will rewrite the string in the correct way 
            st.pop();
        }

        if(res.size() == 0){
            return "/" ;
        }
        return res ;
    }
};