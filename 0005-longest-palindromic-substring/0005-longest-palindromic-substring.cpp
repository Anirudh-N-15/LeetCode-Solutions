class Solution {
public:
    bool isPalindrome(int left,int right,string &s) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false ;
            }
            left++ ;
            right-- ;
        }
        return true ;
    }

    void f(int start,int end,string &s, string &ans) {
        int n = s.size();
        if(start >= n) return ;
        if(end >= n) {
            f(start+1,start+1,s,ans);
            return ;
        }

        if(isPalindrome(start,end,s)) {
            if((end - start + 1) > ans.size()) {
                ans = s.substr(start,end-start+1);
            }
        }

        return f(start, end+1, s, ans);
    }

    string longestPalindrome(string s) {
        string ans = "";
        f(0,0,s,ans);
        return ans;
    }
};