class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "" ;
        string smallest = strs[0] , largest =strs[0] ; 

        for(auto &str : strs){
            if( str < smallest ){
                smallest = str ;
            }
        }
        for(auto &str : strs){
            if( str > largest){
                largest = str ;
            }
        }
        int i=0;
        while(i<smallest.size()){
            if(largest[i] == smallest[i]){
                ans += smallest[i] ;
            }
            else
            break; 

            i++ ;
        }

        return ans ;
    }
};