class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st ;

        for(int& num : asteroids) {
            bool flag = false ;
            while(!st.empty() && (st.top() > 0 && num < 0)) {
                if(st.top() + num == 0) {
                    flag = true ;
                    st.pop();
                    break;
                }
                if(st.top() + num > 0) {
                    flag = true ;
                    break;
                } else {
                    st.pop();
                }
            }
            if(flag == true ) continue ;
            st.push(num);
        }
        vector<int> ans ;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};