class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<int> st ;

        for(int i=0;i<=pattern.size();++i) {
            // until I is seen/till pattern.size has been reached we push numbers onto the stack
            st.push(i+1);  
            //when we have reached pattern.size or seen I then we empty the stack, as to ensure lexicogaphically smallest pattern
            if(i == pattern.size() || pattern[i] == 'I') {
                while(!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        return result ;    
    }
};