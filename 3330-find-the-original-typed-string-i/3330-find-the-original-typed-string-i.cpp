class Solution {
public:
    int possibleStringCount(string word) {
        stack<char> st ;
        int count =1;
        st.push(word[0]);

        for(int i=1;i<word.size();++i){
            if(st.top()==word[i]){
                count++ ;
            }
                st.push(word[i]);
        }
        return count ;
    }
};