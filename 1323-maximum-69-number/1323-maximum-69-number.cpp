class Solution {
public:
    int maximum69Number (int num) {
        string numstring = to_string(num);
        int i=0 ;

        while(i<numstring.length()){
            if(numstring[i]=='6'){
                numstring[i]='9';
                break;
            }
            i++ ;
        }
        num = stoi(numstring);
        return num ;
    }
};