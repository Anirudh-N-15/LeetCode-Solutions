class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "" ;
        int i=0,j=0;

        while(j<spaces.size()){
            while(i!=spaces[j]){
                ans += s[i];
                i++ ;
            }
            ans += " " ;
            j++ ;
        }

        while(i<s.size()){
            ans += s[i];
            i++ ;
        }

        cout << i << endl ;

        return ans ;
    }
};