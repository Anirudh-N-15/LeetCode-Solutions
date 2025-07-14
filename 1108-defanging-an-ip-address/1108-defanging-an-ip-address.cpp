class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "" ;

        for(const char &ch : address) {
            if(ch >= '0' && ch <= '255'){
                ans += ch ;
            } else {
                ans += "[.]" ;
            }
        }
        return ans ;
    }
};