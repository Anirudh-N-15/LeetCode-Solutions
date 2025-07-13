class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto &ch : tokens) {
            if(ch == "+"){
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                st.push(op1 + op2);
            } else if(ch == "*"){
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                st.push(op1 * op2);
            } else if(ch == "-"){
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                st.push(op2 - op1);
            } else if(ch == "/"){
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                st.push(op2 / op1);
            } else {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};