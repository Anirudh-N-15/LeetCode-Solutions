class Solution {
public:
    const int mod = 1e9 + 7;
    int dfs(int &n, unordered_map<char, vector<char>>& umap,int len,char last,vector<vector<int>>& dp) {
        if(len == n) {
            return 1;
        }
        if(dp[len][last - 'a'] != -1) {
            return dp[len][last - 'a'] ;
        }

        int count = 0;
        for(const auto &ch : umap[last]) {
            count = (count % mod +  dfs(n,umap,len +1,ch,dp) % mod) % mod;
        }
        return dp[len][last - 'a'] = count ;
    }

    int countVowelPermutation(int n) {
        unordered_map<char, vector<char>> umap = {{'a', {'e'}},
                                                  {'e', {'a', 'i'}},
                                                  {'i', {'a', 'e', 'o', 'u'}},
                                                  {'o', {'i', 'u'}},
                                                  {'u', {'a'}}};

        unordered_set<char> uset = {'a','e','i','o', 'u'} ;
        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(26,-1));

        for(auto it : umap) {
            char ch = it.first ;
            int count = 0;
            if(uset.find(it.first) != uset.end()) {
                count = dfs(n,umap,1,ch,dp) % mod ;
                uset.erase(it.first);
            }
            ans =  (ans % mod + count % mod) % mod ;
        }
        return ans ;
    }
};