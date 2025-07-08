class Solution {
public:
    bool isPalindrome(const string &s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false ;
            }
            left++ ;
            right-- ;
        }
        return true ;
    }

    void backtrack(const string &s, int start, vector<string>& path, vector<vector<string>>& ans){
        int n = s.size();
        if(start >= n) {
            ans.push_back(path);
            return ;
        }

        for(int end = start;end < n;end++) {
            if(isPalindrome(s,start,end)) {
                path.push_back(s.substr(start,end-start+1));
                backtrack(s,end+1,path,ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(s,0,path,ans);

        return ans;
    }
};