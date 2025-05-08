class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string smallest = strs[0], largest = strs[0] ;

        for(string &str : strs) {
            if(str > largest) {
                largest = str ;
            } 
            if(str < smallest) {
                smallest = str ;
            }
        }

        int i=0;
        string res = "";
        while(i < smallest.size()) {
            if(smallest[i] != largest[i]){
                break;
            } else {
                res += smallest[i] ;
            }
            i++ ;
        }
        return res ;
    }
};