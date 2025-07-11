//The idea here is to check all substrings from a given char. If it is present in the dictionary
//then we can mark dp arr as true and then continue

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        if(wordDict.empty()) return false ;
        int n = s.size();
        vector<bool> dp(n+1,0);
        dp[0] = true ;  //empty string

        for(int i=1;i<=n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(dp[j]) {//to minimize redundancy
                    string word = s.substr(j,i-j);

                    if(words.find(word) != words.end()){
                        dp[i] = true ;
                    }
                }
            }
        }
        //dp[n] will be true iff there exist a full partition of the string 
        //To understand please dry run a testcase with pen & paper using the code
        return dp[n] ;
    }
};