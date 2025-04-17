class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> omap;
        for(int i=0;i<s.length();++i){
            omap[s[i]]++  ;
        }
        string left="",mid="";
        for(auto &[ch,count] : omap){
            if(count%2 == 1){
                mid = ch ;
            }
            left += string(count/2,ch);
        }
        string right = left;
        reverse(right.begin(),right.end());
        return left + mid + right ;
    }
};