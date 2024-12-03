class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans ;
        ans.reserve(s.size() + spaces.size());
        int i=0,j=0;

        while(i<s.size()){
            if(j<spaces.size() && i == spaces[j]){
                ans += ' ';
                j++ ;
            }
            ans += s[i];
            i++ ;
        }
        return ans ;
    }
};