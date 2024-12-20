class Solution {
public:
    int minLength(string s) {
        stack <char> stk ;

        for(auto &c : s){
            if(!stk.empty() && ((stk.top()=='A' && c=='B') || (stk.top()=='C' && c=='D'))){
                stk.pop();
            }
            else{
                stk.push(c);
            }
        }
        return stk.size() ;
    }
};