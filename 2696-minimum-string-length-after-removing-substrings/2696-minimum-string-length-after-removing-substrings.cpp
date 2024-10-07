class Solution {
public:
    int minLength(string s) {
        bool found = true ;

        while(found){
            found = false ;
            for(int i=0;i<s.size();++i){
            string sub = s.substr(i,2);
                if(sub=="AB" || sub=="CD"){
                    s.erase(i,2);
                    found= true ;
                    break;
                }
            }
        }
        return s.size();
    }
};