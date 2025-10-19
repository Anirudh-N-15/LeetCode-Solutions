class Solution {
public:
    string ans;
    unordered_set<string> visited ;

    string addOp(string s, int a) {
        for(int i=1;i<s.size();i+=2) {
            s[i] = ((s[i] - '0' + a) % 10 ) + '0' ;
        }
        return s ;
    }

    string rotateOp(string s,int b ) {
        int n = s.size() ;
        return s.substr(n - b) + s.substr(0,n - b);
    }

    void dfs(string s, int a, int b) {
        if(visited.count(s)) return ;
        visited.insert(s);

        ans = min(ans,s);

        string addS = addOp(s,a);
        dfs(addS,a,b) ;

        string rotateS = rotateOp(s,b);
        dfs(rotateS,a,b);
    }


    string findLexSmallestString(string s, int a, int b) {
        ans = s ;
        dfs(s,a,b);
        return ans ;
    }
};